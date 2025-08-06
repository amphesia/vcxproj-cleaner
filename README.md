# VCXPROJ RAT Cleaner

This repository contains tools to scan your Windows PC for `.vcxproj` files infected with malicious `<Command>` lines commonly used by Remote Access Trojans (RATs). These tools remove any build commands containing suspicious URLs (`https://`) or executable references (`.exe`) embedded in Visual Studio project files.

---

## Features

- Recursively scans all drives (C: through Z:)
- Targets `.vcxproj` files only
- Removes any `<Command>` lines containing:
  - URLs (`https://`)
  - Executable references (`.exe`)
- Supports two implementations:
  - Python script (`clean_vcxproj.py`)
  - C++ executable (`clean_vcxproj.cpp`)
- Requires administrator privileges for full disk access
- Overwrites infected files directly without backup (use version control or backups)

---

## Usage

### Python Version

1. Ensure Python 3.x is installed on your system.
2. Run the script as Administrator:

```bash
python clean_vcxproj.py
