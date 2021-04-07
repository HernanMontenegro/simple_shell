#include "our_header.h"

/**
 * cmd_alias - 
 * 
*/
void cmd_alias(int ac, char **av)
{
    int i, j;
    int alias_len = 0;
    char *aux = NULL;
    char **aux2 = NULL;
    char **checker = NULL;

    /* Print every alias with a new line */
    if (ac == 1)
    {
        for (i = 0; global_alias[i] != NULL; i++)
        {
            aux = _strcon("alias ", global_alias[i]);
            _print_n(aux);
            free(aux);
        }
        last_child_ret = 0;
        return;
    }
    for (i = 1; av[i] != NULL; i++)
    {
        checker = _split(av[i], "=");
        if (!checker[1])
        {
            for (j = 0; global_alias[j] != NULL; j++)
            {
                aux2 = _split(global_alias[j], "=");
                if (_strcmp(checker[0], aux2[0]) == 0)
                {
                    aux = _strcon("alias ", global_alias[j]);
                    _print_n(aux);
                    free(aux);
                    free_split(aux2);
                    break;
                }
                free_split(aux2);
            }
        }
        else
        {
            alias_len = p_strlen(global_alias);
            global_alias = p_realloc(global_alias, alias_len, alias_len + 2);
            global_alias[alias_len] = av[i];
            global_alias[alias_len + 1] = NULL;
        }

        free_split(checker);
    }
    
    last_child_ret = 0;
}