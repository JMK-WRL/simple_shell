#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "shell.h"

int flag = 0;

void my_signal(int sig)
{
    (void)sig;
    flag = 1;
}

int main_signal(void)
{
    signal(SIGINT, my_signal);
    while (1)
    {
        if (flag)
        {
            flag = 0;
        }
    }
    return 0;
}

