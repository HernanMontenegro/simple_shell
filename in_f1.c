#include "our_header.h"

void cmd_exit(int ac, char **av)
{
	abort_indicator = 1;
    if (ac == 2)
    	abort_indicator_status = _atoi(av[1]);
    else
    	abort_indicator_status = 0;
}