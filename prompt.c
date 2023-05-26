#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "shell.h"

void sig_handler(int signum)
{
    if (signum == SIGINT)
    {
        write(STDOUT_FILENO, "\n$ ", 3);
    }
}


void custom_getline(void)
{
    char *string = NULL;
    size_t size = 0;
    ssize_t bytes_read;

    printf("$ ");
    bytes_read = getline(&string, &size, stdin);

    if (bytes_read == -1)
    {
        puts("ERROR!");
    }
    else
    {
        if (bytes_read > 0 && string[bytes_read - 1] == '\n')
            string[bytes_read - 1] = '\0';

        if (strcmp(string, "exit") == 0)
        {
            free(string);
            exit(0);
        }

        printf("Input: %s\n", string);
    }

    free(string);
}

void custom_strtok(void)
{
    char str[] = " ";
    char *token = strtok(str, " ");

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
}

void _fork(void)
{
    char *argv[] = {"/bin/ls", "-l", ".", NULL};

    pid_t pid = fork();

    if (pid == 0)
    {
        execve(argv[0], argv, NULL);
        exit(0);
    }
    else if (pid > 0)
    {
        wait(NULL);
    }
}

void main_prompt(void)
{
    signal(SIGINT, sig_handler);
    while (1)
    {
        custom_getline();
        custom_strtok();
        _fork();
    }
}

