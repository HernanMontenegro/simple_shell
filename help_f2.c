#include "our_header.h"

void hp_setenv()
{
    _print_n("Create a new environmental variable");
    _print_n("\tUsage: setenv [var name] [value]");
}

void hp_unsetenv()
{
    _print_n("Removes an environmental variable");
    _print_n("\tUsage: unset [var name]");
}