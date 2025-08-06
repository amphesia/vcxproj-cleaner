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

If you prefer a native C++ solution, you can compile and run the provided C++ program:

Create a new C++ project in Visual Studio (ensure it targets C++17 or later).

Replace the content of your main source file (e.g., main.cpp) with the provided clean_vcxproj.cpp code.

Build and run the program as Administrator to perform the cleaning.
---

**Important:** Always back up your files before running the script.
