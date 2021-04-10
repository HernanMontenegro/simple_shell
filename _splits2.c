#include "our_header.h"

/**
 * comms_pross - (Cut off..) activate boolean when
 *                found first comma and detects when it closes
 * @bool_comms: given bool commas in check_split_line
 * @i: index given in check_split_line
 * @j: index given in check_split_line
 * @nxt_comms: when finding the first, this bool will active
 *              indicating that the program should find the close
 *              comma.
 * @t_comms: type of commas 
 * 
*/
void comms_pross(int *bool_comms, int *i, int *j, int *nxt_comms, int *t_comms)
{
    if ((*bool_comms) == -1)
    {
        for (*j = 1; s[*i + *j] != '\0'; *j++)
        {
            if (s[*i + *j] == s[*i])
            {
                *nxt_comms = 1;
                break;
            }
        }
        if (*nxt_comms && *t_comms == 0)
        {
            *bool_comms = *bool_comms * -1;
            *t_comms = s[*i];
        }
    }
    else
    {
        if (*t_comms == s[*i])
        {
            *bool_comms = *bool_comms * -1;
            *t_comms = 0;
        }
    }
}