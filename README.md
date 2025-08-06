# .vcxproj Files cleaner [for luckyware / luckyminer]

This script scans `.vcxproj` files on your computer to find and remove luckyminers Remote Access Trojans (RATs). It helps keep your Visual Studio project files clean and safe.

## How It Works

- Runs with Administrator privileges to access all files.
- Searches drives `C:` through `Z:` for `.vcxproj` files.
- Checks each file line by line for malicious `<Command>` entries.
- Removes any detected malicious lines and updates the file.
- Prints status messages for each file processed.

## Usage

### Python

Run the script using Python with Administrator rights:

`python clean_vcxproj.py`

### C++

If you use Visual Studio for C++ projects, this script cleans your `.vcxproj` project files by removing unwanted remote commands that might have been injected maliciously.

Simply create a new project in Visual Studio and paste clean_vcxproj.cpp into your main.cpp, make sure its c++ v17.

---

**Important:** Always back up your files before running the script.
