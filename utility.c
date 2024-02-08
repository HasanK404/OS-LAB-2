// OS-Lab-2
// Jumaana Aslam - 10778027
// Hasan Khan - 100820450
// Somya Babar - 100851536
#include "myshell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Change the current working directory
void change_directory(char *path) {
    // Check if no path is provided
    if (path == NULL) {
        char cwd[1024];
        // Get the current working directory
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            // Print the current working directory
            printf("%s\n", cwd);
        } else {
            perror("getcwd() error");
        }
    } else {
        // Change directory to the specified path
        if (chdir(path) != 0) {
            // Print error if unable to change directory
            perror("myshell");
        }
    }
}
// Clear the screen
void clr() {
    printf("\033[H\033[J"); // ANSI escape sequence to clear the screen
}
// List the contents of a directory
void list_directory(char *path) {
    // Check if no path is provided, set path to current directory
    if (path == NULL) {
        path = ".";
    }

    // Create command to list directory contents
    char command[1024];
    sprintf(command, "ls -l %s", path);
    // Execute the command using system call
    system(command);
}
// Display environment variables
void display_environment() {
     // Access the external environment variable
    extern char **environ;
    // Iterate through the environment variables and print each one
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
}
// Display a comment on the display
void display_comment(char *comment) {
    printf("%s\n", comment);
}

// Display help information
void display_help() {
    // You can replace this with the actual help content
    printf("Help: This is a simple shell. Available commands: cd, clr, dir, environ, echo, help, pause, quit\n");
}

// Pause the operation of the shell until 'Enter' is pressed
void pause_shell() {
    printf("Press Enter to continue...\n");
    getchar(); // Wait for Enter key
}

