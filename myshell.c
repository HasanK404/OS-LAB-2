#include "myshell.h"

void execute_command(char *input) {
    char *token;
    char *args[1024]; // Array to hold command and its arguments
    int i = 0;

    char *delim = " \n";
    token = strtok(input, delim);

    while (token != NULL && i < 1023) {
        args[i++] = token;
        token = strtok(NULL, delim);
    }

    args[i] = NULL; // Null-terminate the array

    if (i > 0) {
        if (strcmp(args[0], "cd") == 0) {
            change_directory(args[1]);
        } else if (strcmp(args[0], "clr") == 0) {
            clr();
        } else if (strcmp(args[0], "dir") == 0) {
            list_directory(args[1]);
        } else if (strcmp(args[0], "environ") == 0) {
            display_environment();
        } else if (strcmp(args[0], "echo") == 0) {
            display_comment(args[1]);
        } else if (strcmp(args[0], "help") == 0) {
            display_help();
        } else if (strcmp(args[0], "pause") == 0) {
            pause_shell();
        } else if (strcmp(args[0], "quit") == 0) {
            exit(0);
        } else {
            pid_t child_pid = fork();

            if (child_pid == -1) {
                perror("Fork failed");
            } else if (child_pid == 0) {
                // Child process
                char parent_env[1024];
                sprintf(parent_env, "parent=%s", getenv("PWD"));
                setenv("parent", parent_env, 1);

                // Execute the external command
                if (execvp(args[0], args) == -1) {
                    perror("Exec failed");
                }

                // Exit the child process
                exit(0);
            } else {
                // Parent process
                wait(NULL); // Wait for the child process to finish
            }
        }
    }
}
            
int main(int argc, char *argv[]) {
    char input[1024]; // Buffer for user input

    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Error opening file");
            return 1;
        }

        while (fgets(input, sizeof(input), file) != NULL) {
            printf("Executing: %s", input);
            execute_command(input);
        }

        fclose(file);
        return 0; // Exit after processing commands from file
    } else {
        while (1) {
            printf("MyShell> ");
            printf("Type 'quit' to exit\n");

            if (fgets(input, sizeof(input), stdin) == NULL) {
                break; // Exit on EOF
            }

            // Remove newline character from the input
            input[strcspn(input, "\n")] = '\0';

            if (strcmp(input, "quit") == 0) {
                break; // Exit if the user types 'quit'
            }

            execute_command(input); // Process the input
        }

        return 0;
    }
}
