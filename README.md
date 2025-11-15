# Simple Shell

A basic Unix shell implementation in C.

## Features

- Execute commands with arguments
- Built-in `cd` and `exit` commands  
- Error handling

## Building
```bash
gcc -Wall -Wextra -o shell shell.c
./shell
```

## Example
```bash
myshell> ls -la
myshell> cd /tmp
myshell> pwd
/tmp
myshell> exit
```

## Implementation

Uses `fork()` to create child processes and `execvp()` to execute commands. Built-in commands like `cd` are handled directly by the shell without forking.

## What I Learned

- Process management with fork/exec pattern
- Why certain commands must be built-in
- How Unix shells work at a low level
