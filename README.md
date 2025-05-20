# Intro-to-cpp: Project 1 

# Command-Driven Data Processor

This C++ program processes numeric data from external files based on a set of commands provided via a **command file**. It supports basic arithmetic operations (addition and subtraction), file switching, and summary reporting.

## 📄 Description

The program reads a command file that contains a sequence of operations to perform on one or more data files. Supported commands include:

- `OPEN <filename>` – Opens a new data file and resets reading from it.
- `ADD <N>` – Adds the next N numbers from the current data file to a running sum.
- `SUB <N>` – Subtracts the next N numbers from the current data file from the sum.
- `REPORT <TYPE>` – Reports the current status. Supported types:
  - `SUM`
  - `AVERAGE`
  - `COUNT` (number of values processed)
  - `COMMANDS` (number of commands processed)
- `QUIT` – Exits the program.

## ⚙️ How It Works

- Input is taken from a **command file**, entered by the user at runtime.
- The program performs actions specified in the command file using one or more associated data files.
- Results are displayed to the console.
- It keeps track of:
  - Total sum
  - Number of values processed
  - Number of commands processed

## 🧪 Example Command File

```plaintext
OPEN data1.txt
ADD 5
SUB 2
REPORT AVERAGE
REPORT SUM
REPORT COUNT
QUIT

## 📝 Notes

- If a data file is already open, it is **exhausted** before opening a new one (remaining values are read and skipped).
- Invalid commands or input parameters will trigger error messages.
- The program assumes all numbers in the data file are valid floating-point values.

