# RAT Cleaner for .vcxproj Files

This Python script scans all `.vcxproj` files across available drives on a Windows system and removes lines containing potential Remote Access Trojan (RAT) commands.

## How It Works

- The script searches for `.vcxproj` files starting from all available drive letters (C: to Z:).
- For each file, it looks for lines matching a specific pattern that indicates a malicious command referencing URLs (`https://`) or executable files (`.exe`) inside `<Command>` tags.
- If such lines are found, they are removed and the file is overwritten with the cleaned content.
- The script requires administrator privileges to ensure it can access all files.

## Usage

1. Run the script as an Administrator (required to access all files).
2. The script will scan all drives and clean `.vcxproj` files automatically.
3. Output messages indicate which files were cleaned or found clean.

## Requirements

- Python 3.x
- Windows OS (due to use of `ctypes` for admin check and drive scanning)

## Disclaimer

Use this script carefully and make sure to backup your files before running it.

---

*Developed to help remove malicious RAT commands embedded in Visual Studio project files.*
