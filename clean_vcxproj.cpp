#include <iostream>
#include <filesystem>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <windows.h>

namespace fs = std::filesystem;

bool IsAdmin() {
    BOOL isAdmin = FALSE;
    PSID administratorsGroup = NULL;
    SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;

    if (AllocateAndInitializeSid(&ntAuthority, 2,SECURITY_BUILTIN_DOMAIN_RID,DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &administratorsGroup)) {
        CheckTokenMembership(NULL, administratorsGroup, &isAdmin);
        FreeSid(administratorsGroup);
    }
    return isAdmin == TRUE;
}

bool RemoveRatFromFile(const fs::path& filePath, const std::regex& ratPattern) {
    std::ifstream fileIn(filePath);
    if (!fileIn.is_open()) {
        std::cerr << "[ERROR]   " << filePath << " - Unable to open file for reading\n";
        return false;
    }

    std::vector<std::string> lines;
    std::string line;
    bool modified = false;

    while (std::getline(fileIn, line)) {
        if (std::regex_match(line, ratPattern)) {
            modified = true;
        } else {
            lines.push_back(line);
        }
    }
    fileIn.close();

    if (modified) {
        std::ofstream fileOut(filePath, std::ios::trunc);
        if (!fileOut.is_open()) {
            std::cerr << "[ERROR]   " << filePath << " - Unable to open file for writing\n";
            return false;
        }
        for (const auto& l : lines) {
            fileOut << l << "\n";
        }
        fileOut.close();
        std::cout << "[CLEANED] " << filePath << "\n";
    } else {
        std::cout << "[OK]      " << filePath << " - no malicious line found\n";
    }
    return true;
}

void FindAndCleanVcxproj(const fs::path& startPath, const std::regex& ratPattern) {
    std::error_code ec;
    for (auto& p : fs::recursive_directory_iterator(startPath, fs::directory_options::skip_permission_denied, ec)) {
        if (ec) continue;

        if (p.is_regular_file() && p.path().extension() == ".vcxproj") {
            RemoveRatFromFile(p.path(), ratPattern);
        }
    }
}

int main() {
    if (!IsAdmin()) {
        std::cerr << "Please run this program as Administrator to access all files.\n";
        return 1;
    }

    std::cout << "Scanning for .vcxproj files and removing RAT commands...\n\n";

    std::regex ratPattern(R"(\s*<Command>.*(https://|\.exe).*?</Command>\s*)", std::regex_constants::icase);

    for (char drive = 'C'; drive <= 'Z'; ++drive) {
        std::string drivePath = std::string(1, drive) + ":\\";
        if (fs::exists(drivePath)) {
            FindAndCleanVcxproj(drivePath, ratPattern);
        }
    }

    std::cout << "\nDone.\n";
    return 0;
}
