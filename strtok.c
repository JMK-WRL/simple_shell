#include <stdio.h>
#include <string.h>

void _strtok(char *str, const char *token)
{
    char *token_ptr = strtok(str, token);

    while (token_ptr != NULL)
    {
        printf("%s\n", token_ptr);
        token_ptr = strtok(NULL, token);
    }
}

