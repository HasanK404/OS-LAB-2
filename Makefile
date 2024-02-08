#Makefile
#OS-Lab-2
# Group - 13 - CRN- 74025
# Jumaana Aslam - 10778027
# Hasan Khan - 100820450
# Somya Babar - 100851536

all: myshell

myshell: myshell.c utility.c
	gcc -o myshell myshell.c utility.c -I.


