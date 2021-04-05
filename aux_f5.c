#include "our_header.h"

/**
 * env_index - Find the env name index
 * @env_name: the env variable to look for
 * --------------------------------------------
 * Return: the index where the var is located
*/ 
int get_env_index(char *env_name)
{
    int i, res = 0;
    char **aux = NULL;

    for (i = 0; global_env[i] != NULL; i++)
    {
        aux = _split(global_env[i], "=");
        if (_strcmp(aux[0], env_name) == 0)
        {
            free_split(aux);
            res = i;
            break;
        }
        free_split(aux);
    }

    return (res);
}