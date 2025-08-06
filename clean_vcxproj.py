import os
import re
import ctypes

rat_pattern = re.compile(r'\s*<Command>.*(https://|\.exe).*?</Command>\s*', re.IGNORECASE)

def is_admin():
    try:
        return ctypes.windll.shell32.IsUserAnAdmin()
    except:
        return False

def remove_rat_from_file(file_path):
    try:
        with open(file_path, 'r', encoding='utf-8') as f:
            lines = f.readlines()

        cleaned_lines = [line for line in lines if not rat_pattern.match(line)]

        if len(cleaned_lines) != len(lines):
            with open(file_path, 'w', encoding='utf-8') as f:
                f.writelines(cleaned_lines)
            print(f"[CLEANED] {file_path}")
        else:
            print(f"[OK]      {file_path} - no malicious line found")
    except Exception as e:
        print(f"[ERROR]   {file_path} - {e}")

def find_and_clean_vcxproj(start_path):
    for root, dirs, files in os.walk(start_path):
        for file in files:
            if file.endswith(".vcxproj"):
                file_path = os.path.join(root, file)
                remove_rat_from_file(file_path)

if __name__ == "__main__":
    if not is_admin():
        print("Please run this script as Administrator to access all files.")
        os.system("pause")

    print("Scanning for .vcxproj files and removing RAT commands...\n")
    for drive_letter in 'CDEFGHIJKLMNOPQRSTUVWXYZ':
        drive = f"{drive_letter}:/"
        if os.path.exists(drive):
            find_and_clean_vcxproj(drive)

    print("\nDone.")
