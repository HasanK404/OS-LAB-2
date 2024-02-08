# LAB 2
## Introduction
Welcome to `myshell`, a simple command-line interpreter that mimics basic Unix shell functionality. This README serves as a guide for users to understand how to operate `myshell` effectively.

## Features
`myshell` supports the following internal commands:
1. `cd <directory>`: Change the current default directory to `<directory>`. If `<directory>` is not provided, it reports the current directory. An appropriate error is reported if `<directory>` does not exist. This command also updates the `PWD` environment variable.
2. `clr`: Clear the screen.
3. `dir <directory>`: List the contents of directory `<directory>`.
4. `environ`: List all the environment strings.
5. `echo <comment>`: Display `<comment>` on the display followed by a new line. Multiple spaces/tabs may be reduced to a single space.
6. `help`: Display the user manual using the more filter.
7. `pause`: Pause operation of the shell until 'Enter' is pressed.
8. `quit`: Quit the shell.

`myshell` supports external command as well using the fork and exec method by following these step :
- If the command is recognized as an internal command, it is executed directly.
- If it's not an internal command, the shell forks a child process.
- In the child process, we set the parent environment variable using the setenv function.
- The external command is then executed using execvp.
- The parent process waits for the child process to finish using wait(NULL)

  Try these to test out:
1. `pwd`:  prints the current working directory.
2. `ls`:  is a basic command that lists the contents of the current directory.
3. `echo`: is used to print a message.
4. `date`: prints the current date and time.

# Installation & Usage
To install `myshell`, follow these steps:
1. Clone the repository to your local machine.
   ```bash
   git clone OS-LAB-2
3. Navigate to the directory containing the source code.
   ```bash
   cd myshell
5. Compile the source code using the provided Makefile.
    ```bash
   make
7. Run the compiled executable file.
   ```bash
   ./myshell

## I/O Redirection
`myshell` supports I/O redirection using the following symbols:
- `<`: Redirects input from a file.
- `>`: Redirects output to a file.
- `>>`: Appends output to a file.

## Exiting `myshell`
To exit `myshell`, simply type the `quit` command or press `Ctrl + D`.

- Jumaana Aslam - 100778027
- Hasan Khan - 100820450
- Somya Babar - 100851536
