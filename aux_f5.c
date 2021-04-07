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

/**
 * _print_n - print a string with a new line at the end
 * @str: the string to print
 * -------------------------------
*/
void _print_n(char *str)
{
    char *aux = NULL;

    aux = _strcon(str, "\n");
    _print(aux);
    free(aux);
}

/**
 * 
 * 
*/
char **create_start_alias()
{
    int i = 0;
    char **aux = malloc(9 * sizeof(char *));

    aux[i++] = "egrep='egrep --color=auto'";
    aux[i++] = "fgrep='fgrep --color=auto'";
    aux[i++] = "grep='grep --color=auto'";
    aux[i++] = "l='ls -CF'";
    aux[i++] = "la='ls -A'";
    aux[i++] = "ll='ls -alF'";
    aux[i++] = "ls='ls --color=auto'";
    aux[i++] = NULL; 

    return (aux);
}