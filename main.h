#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <dirent.h>
#include <stdbool.h>
#include <dirent.h>
#include <libgen.h>

#define MAX_PATH_LENGTH 4096
#define MAX_CHAR_LENGTH 1024
#define MAX_BUFFER_SIZE 1024
#define MAX_LINE 80
#define ENV_NOT_FOUND NULL

/**
* struct Node - Structure of a node linked list
* @directory: A pointer to a character string that
* represents the name of a directory.
* @next: A pointer to the next node in the linked list.
*/
typedef struct Node
{
	char *directory;
	struct Node *next;
}

Node;

extern char **environ;

#endif