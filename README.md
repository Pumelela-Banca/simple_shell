# simpleShell

## Overview

simpleShell is a custom Linux shell program written in C that replicates core functionalities of a Unix/Linux shell. The project was developed to strengthen understanding of low-level systems programming, process management, memory handling, and how shells interact with the operating system.

A major requirement of the project was to avoid relying on many standard C library functions. Instead, several utility functions were implemented from scratch, including custom input/output and string handling functions.

---

## Features

* Command execution
* File and directory navigation
* File listing
* Interactive mode
* Non-interactive mode
* Error handling for invalid commands
* Custom-built utility functions
* Process execution using system calls

---

## Technologies Used

* C Programming Language
* Linux/Unix environment
* GCC compiler

---

## Project Objectives

The goal of this project was to:

* Understand how Linux shells work internally
* Learn systems programming concepts
* Practice process creation and execution
* Implement low-level functions without depending on built-in C methods
* Improve debugging and error-handling skills

---

## Custom Implementations

To meet project requirements, several standard functions were recreated manually, including:

* `_putchar`
* Custom read functions
* String manipulation utilities
* Input parsing functions

This helped develop a deeper understanding of how common C library functions work internally.

---

## Modes Supported

### Interactive Mode

Allows users to type commands directly into the shell and receive immediate output.

Example:

```bash
$ ./simpleShell
$ ls
$ pwd
```

### Non-Interactive Mode

Allows commands to be piped into the shell.

Example:

```bash
echo "ls" | ./simpleShell
```

---

## Compilation

Compile the project using GCC:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simpleShell
```

---

## Running the Shell

Start interactive mode:

```bash
./simpleShell
```

Run in non-interactive mode:

```bash
echo "command" | ./simpleShell
```

---

## Error Handling

The shell includes error handling mechanisms to:

* Detect invalid commands
* Handle incorrect input
* Display meaningful error messages
* Prevent crashes during execution

---

## Learning Outcomes

Through this project, I gained practical experience in:

* Systems programming
* Linux process management
* Parsing command-line input
* Memory management
* Writing modular C code
* Debugging low-level applications

---

## Future Improvements

Possible future enhancements include:

* Environment variable support
* Command history
* Piping and redirection
* Advanced shell built-ins
* Improved autocomplete and suggestions

---

## Author

Pumelela Banca
