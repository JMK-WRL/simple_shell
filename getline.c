#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include "shell.h"

void _signal(void)
{
    signal(SIGINT, SIG_IGN);
    while (1)
    {
        sleep(1);
    }
}

void main_getline(void)
{
    signal(SIGINT, sig_handler);
    while (1)
    {
        custom_getline();
        _signal();
    }
}

