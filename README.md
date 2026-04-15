# Virtual File System (C++)

## Overview
We implemented a command-line virtual file system in C++ for CSE332: CSE 332S: Object-Oriented Software Development. The system simulates common file system operations such as file creation, deletion, reading/writing, copying, and renaming, along with support for multiple file types and password-protected files. This project emphasizes modular design, extensibility, and clean abstraction of system components.

---

## Features

### Core Commands
- `touch` — Create files (`.txt`, `.img`, `.scp`)
- `ls` — List directory contents (supports metadata flag `-m`)
- `cat` — Write to or append file contents (`-a`)
- `ds` — Display file contents (formatted or raw)
- `cp` — Copy files (preserves content and passwords)
- `rm` — Remove files
- `rn` — Rename files
- `help` — Display available commands and usage

### File Types
- **Text files (`.txt`)**
- **Image files (`.img`)**
  - Stored as formatted pixel grids
- **Script files (`.scp`)**
  - Store sequences of commands for execution

### Advanced Features
- Password-protected files via a **Proxy pattern**
- Command system implemented using the **Command pattern**
- File creation handled through a **Factory pattern**
- File display implemented using the **Visitor pattern**
- Macro command (`tcd`) combining touch → cat → display
- Script execution via `run` command

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

## Script Execution
```bash
run script.scp
```

---
## Repository Structure
.
├── src/        # Core implementation
├── include/    # Header files
├── lib/        # Supporting libraries
├── tests/      # Provided test suite used for validation
├── docs/       # Design notes and extended documentation
└── README.md

---

## Contributors
- Sandro Xiao
- Nicole Dai
