#include "shell.h"

/**
 * main - prompt the user for an input
 * Return: Users input
 */

int main(int argc, char **argv)
{
    char *PR = "MyShell> # "; /* user prompt */
    char *line_read = NULL; /* reads a new string */
    char *line_ptr = NULL; /* stores string */
    const char *delim = " \n"; /* breaks string into parts */
    char *token;
    size_t str = 0; /* locate mem */
    ssize_t Eprompt;
    int tk = 0;
    int m;

    /* void variables */
    (void)argc;

    /* Looping for the prompt */
    while (1) {
        write(STDOUT_FILENO, PR, strlen(PR)); /* write prompt to standard output */
        Eprompt = getline(&line_read, &str, stdin);

        if (Eprompt == -1) {
            write(STDOUT_FILENO, "Session ended...\n Exiting shell!\n", strlen("Session ended...\n Exiting shell!\n"));
            return (-1);
        }

        line_ptr = malloc(sizeof(char) * Eprompt);
        if (line_ptr == NULL) {
            write(STDOUT_FILENO, "Error!: Memory setting", strlen("Error!: Memory setting"));
            return (-1);
        }

        /* copy new sting to the string store */
        strcpy(line_ptr, line_read);

        /* calculate the number of tokens */
        token = strtok(line_ptr, delim);

        while (token != NULL) {
            tk++;
            token = strtok(NULL, delim);
        }
        tk++;

        /* allocate mem to hold the strings */
        argv = malloc(sizeof(char *) * tk);

        /* token store */
        token = strtok(line_ptr, delim);

        for (m = 0; token != NULL; m++) {
            argv[m] = malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(argv[m], token);

            token = strtok(NULL, delim);
        }

        argv[m] = NULL;

        /* command execution */
        execute(argv[0]);

        /* free allocated mem for getline */
        free(line_read);
        free(line_ptr);
        free(argv);
        line_read = NULL;
        argv = NULL;
    }

    return (0);
}


