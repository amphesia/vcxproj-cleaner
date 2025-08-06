# RAT Remover for .vcxproj Files

This script scans `.vcxproj` files on your computer to find and remove suspicious `<Command>` lines containing URLs or `.exe` references, which are commonly used by Remote Access Trojans (RATs). It helps keep your Visual Studio project files clean and safe.

## How It Works

- Runs with Administrator privileges to access all files.
- Searches drives `C:` through `Z:` for `.vcxproj` files.
- Checks each file line by line for malicious `<Command>` entries.
- Removes any detected malicious lines and updates the file.
- Prints status messages for each file processed.

## Usage

### Python

Run the script using Python with Administrator rights:

`python remove_rat.py`

### C++

If you use Visual Studio for C++ projects, this script cleans your `.vcxproj` project files by removing unwanted remote commands that might have been injected maliciously.

Simply run the Python script before building your projects to ensure no malicious commands remain.

---

**Important:** Always back up your files before running the script.
