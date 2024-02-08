// OS-Lab-2
// Jumaana Aslam - 10778027
// Hasan Khan - 100820450
// Somya Babar - 100851536
#ifndef MYSHELL_H
#define MYSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void change_directory(char *path);
void clr();
void list_directory(char *path);
void display_environment();
void display_comment(char *comment);
void display_help();
void pause_shell();

#endif

