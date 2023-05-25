#include "shell.h"

/**
 * execute - executes the command passed to it
 * @cmd: command to be executed
 * Return: 0 (success), -1 on failure
 */

int execute(char *cmd)
{
    char *cmd_path = NULL;
    const char *not_found_msg = "Error: Command '%s' not found.\nPlease enter a valid command.\n";
    const char *execution_failed_msg = "Error: Failed to execute the command '%s'. Check the command and try again.\n";
    int exec_status;
    char *tokens[2];

    if (cmd)
    {
        cmd_path = get_position(cmd);

        /* Check if the command exists */
        if (cmd_path == NULL)
        {
            printf(not_found_msg, cmd);
            return -1;
        }

        /* Tokenize the command and arguments */
        tokens[0] = cmd;
        tokens[1] = NULL;

        /* Execute the command using execve */
        exec_status = execve(cmd_path, tokens, NULL);
        if (exec_status == -1)
        {
            printf(execution_failed_msg, cmd);
            return -1;
        }
    }

    return 0;
}

