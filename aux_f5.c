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

    aux[i++] = _strcpy("egrep='egrep --color=auto'");
    aux[i++] = _strcpy("fgrep='fgrep --color=auto'");
    aux[i++] = _strcpy("grep='grep --color=auto'");
    aux[i++] = _strcpy("l='ls -CF'");
    aux[i++] = _strcpy("la='ls -A'");
    aux[i++] = _strcpy("ll='ls -alF'");
    aux[i++] = _strcpy("ls='ls --color=auto'");
    aux[i++] = NULL; 

    return (aux);
}

/**
 * 
 * 
*/
char **change_command_alias(char **baby_av)
{
    int i = 0;
    char **aux = NULL;
    char **aux2 = NULL;
    char **aux3 = NULL;

    for (i = 0; global_alias[i] != NULL; i++)
    {
        aux = _split(global_alias[i], "=");
        
        if (_strcmp(aux[0], baby_av[0]) == 0)
        {
            aux2 = _split(aux[1], " ");

            free(baby_av[0]);
            baby_av[0] = _strcpy("");

            aux3 = p_strcon(aux2, baby_av);
            free_split(aux);
            free_split(aux2);

            if (aux3 == NULL)
                return(baby_av);

            return (aux3);
        }
        free_split(aux);
    }

    return (NULL);
}

/**
 * 
 * 
*/
char **p_strcon(char **p, char **p2)
{
    int i = 0, j;
    int len = 0;
    char **new_p = NULL;

    len = p_strlen(p) + p_strlen(p2) + 1;
    new_p = malloc(len * sizeof(char *));

    for (j = 0; p[j] != NULL; j++)
        new_p[i++] = _strcpy(p[j]);

    for (j = 0; p2[j] != NULL; j++)
        new_p[i++] = _strcpy(p2[j]);
    new_p[i++] = NULL;

    return (new_p);
}