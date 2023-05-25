#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

/* Prompt.c */
int main(int argc, char **argv);

/* execute.c */
int execute(char *cmd);

/* position.c */
char *get_position(char *cmd);

#endif


