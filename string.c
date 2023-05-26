#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int _strlen(char *s)
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

int main_string(void)
{
    char str[] = "Hello, World!";
    int length = _strlen(str);
    printf("Length of the string: %d\n", length);
    return 0;
}

