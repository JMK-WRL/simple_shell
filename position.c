#include "shell.h"

char *get_position(char *cmd){
        char *path;
        char *path_dup; /* path duplicate */
        char *path_tk; /* tokens */
        char *file_path;
        int cmd_len; /* length of the command */
        int dir_len; /* length of the directory */
        struct stat buffer; /* returns information about a file */

        path = getenv("PATH");

        if (path){

                /* duplicating 'path' */
                path_dup = strdup(path);
                /* length of command passed */
                cmd_len = strlen(cmd);
                /* finding the dir in the path */
                path_tk = strtok(path_dup, ":");

                while(path_tk != NULL){
                        dir_len = strlen(path_tk);
                        /* allocating mem to store the commands and dir */
                        file_path = malloc(cmd_len + dir_len + 2);
                        /* copying dir path */
                        strcpy(file_path, path_tk);
                        strcat(file_path, "/");
                        strcat(file_path, cmd);
                        strcat(file_path, "\0");

                        /* testing file position */
                        if (stat(file_path, &buffer) == 0){
                                free(path_dup);

                                return (file_path);
                        }
                        else{
                                free(file_path);
                                path_tk = strtok(NULL, ":");
                        }
                }

                /* free up mem */
                free(path_dup);

                /* checking if the command exists in the buffer */
                if (stat(cmd, &buffer) == 0)
                {
                        return (cmd);
                }

                return (NULL);
        }


        return (NULL);
}

