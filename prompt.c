#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

/**
 * _getline - function that reads a line of input from the user
 * Return: The input string read from the user
 */
char *_getline(void)
{
    char *string = NULL;
    size_t size = 0;
    ssize_t bytes_read = getline(&string, &size, stdin);

    if (bytes_read == -1)
    {
        if (feof(stdin))
        {
            printf("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("getline");
            exit(EXIT_FAILURE);
        }
    }

    return string;
}

/**
 * execute_command - function that executes a command
 * @command: The command to be executed
 */
void execute_command(const char *command)
{
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execlp(command, command, NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }
}

/**
 * sig_handler - signal handler for SIGINT
 * @signum: The signal number
 */
void sig_handler(int signum)
{
    if (signum == SIGINT)
    {
        printf("\n");
        printf("$ ");
        fflush(stdout);
    }
}

/**
 * main - main function
 * Return: Always 0
 */
int main(void)
{
    char *command;
    signal(SIGINT, sig_handler);

    while (1)
    {
        printf("$ ");
        fflush(stdout);

        command = _getline();
        command[strlen(command) - 1] = '\0';

        execute_command(command);

        free(command);
    }

    return 0;
}

