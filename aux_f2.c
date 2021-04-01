#include "our_header.h"

/**
* free_split - frees a splitted string
* @splitted: the splitted string
* @line: the lines to split
*/
void free_split(char **splitted, int line)
{
        int i;

        for (i = 0; i < line; i++)
                free(splitted[i]);
        free(splitted);
}
