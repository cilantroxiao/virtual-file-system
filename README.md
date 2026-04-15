# Virtual File System and Command-Line Shell in C++

## Overview
We implemented a virtual file system and command-line shell in C++ for CSE332: Object-Oriented Software Development at Washington University in St. Louis. The project simulates common file system operations such as creating, deleting, reading/writing, copying, and renaming files, and supports multiple file types as well as password-protected files. \
The system is designed around core operating system concepts, including file abstraction, command dispatching, and extensible runtime behavior through a modular command architecture.

---

## Features
### File System
- In-memory file system
- Supports multiple file types:
  - Text files (`.txt`)
  - Image files (`.img`)
  - Script files (`.scp`)

### Commands
The system runs through a command prompt and supports:
- `touch` — create a file
- `cat` — write to or append a file
- `ds` — display file contents
- `ls` — list files (with optional metadata)
- `cp` — copy files
- `rm` — remove files
- `rn` — rename files
- `run` — execute script files
- `help` — show available commands
## Additional Features

### Password-Protected Files
Files can optionally be protected with a password. Accessing them requires authentication before read/write operations.

### Script Files
Script files (`.scp`) store a list of commands. The `run` command executes them line by line like a simple automation script.

### Macro Commands
Some commands combine multiple operations together. For example:
- `tcd` = touch → cat → display
- `rn` = copy → remove (rename behavior)

---

## Design
The project is built using several object-oriented design patterns:
- **Command Pattern** — each command is implemented as its own class
- **Factory Pattern** — used to create different file types
- **Proxy Pattern** — used for password-protected files
- **Visitor Pattern** — used for different ways of displaying files
- **Macro Commands** — combine multiple commands into one

---

## Example Usage

```bash
touch file.txt
cat file.txt
# write content, then :wq

ls -m
ds file.txt

cp file.txt copy
rn file.txt newname
rm copy.txt
```
---
## Repository Structure
```bash
├── src             # Entry point for each lab. Lab5.cpp
├── include         # Core implementation of system, file types, commands
├── lib             # Hader files for abstract classes and interfaces
├── provided_tests  # Provided course test suite (no modification)
├── docs            # Notes and documentation for class submission
    └── archive     # Other notes for past checkpoint submissions
├── CMakeLists.txt
└── README.md  
```
---

## Contributors
- Sandro Xiao
- Nicole Dai
