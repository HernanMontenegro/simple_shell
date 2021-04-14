#include "our_header.h"

int check_num(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }

    return (1);
}