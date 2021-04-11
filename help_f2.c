#include "our_header.h"

/**
 * hp_setenv - help for command setenv
 * ----------------------------------
*/
void hp_setenv(void)
{
	_print_n("Create a new environmental variable");
	_print_n("\tUsage: setenv [var name] [value]");
}

/**
 * hp_unsetenv - help for command unsetenv
 * ----------------------------------
*/
void hp_unsetenv(void)
{
	_print_n("Removes an environmental variable");
	_print_n("\tUsage: unset [var name]");
}
