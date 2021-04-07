#include "our_header.h"

/**
 * 
*/
void hp_help()
{
    _print_n("Usage: help [internal command name]");
}

/**
 * 
*/
void hp_exit()
{
    _print_n("exit: exit [n]");
    _print_n("\tExit the shell.");
    _print_n(" ");
    _print("Exits the shell with a status of N.");
    _print_n(" If N is omitted, the exit status");
    _print_n("is that of the last command executed.");
}

/**
 * 
*/
void hp_cd()
{
    _print_n("cd: cd [-L|[-P [-e]] [-@]] [dir]");
    _print_n("\tChange the shell working directory.");
    _print_n(" ");
    _print_n("\tChange the current directory to DIR.");
    _print_n("\tThe default DIR is the value of the HOME shell variable.");
    _print_n("Options:");
    _print_n("-L\tforce symbolic links to be followed:");
    _print_n("  resolve symbolic links in DIR after processing instances of `..'");
    _print_n("-P\tuse the physical directory structure without following");
    _print_n(" symbolic links: resolve symbolic links in DIR before");
    _print_n("processing instances of `..'");
    _print_n("-e\tif the -P option is supplied, and the current working directory");
    _print_n(" cannot be determined successfully, exit with a non-zero status");
    _print_n("-@  on systems that support it, present a file with extended");
    _print_n("extended attributes as a directory containing");
    _print_n(" the file attributes");
    _print_n(" ");
    _print_n("Exit Status:");
    _print_n("Returns 0 if the directory is changed, and if $PWD");
    _print_n(" is set successfully when -P is used; non-zero otherwise.");
}

/**
 * 
*/
void hp_alias()
{
    _print_n("alias: alias [-p] [name[=value] ... ]");
    _print_n("\tDefine or display aliases.");
    _print_n(" ");
    _print_n("\tWithout arguments, `alias' prints the list of aliases");
    _print_n("\tin the reusable form `alias NAME=VALUE' on standard output.");
    _print_n(" ");
    _print_n("\tOtherwise, an alias is defined for each NAME whose VALUE is given.");
    _print_n("\tA trailing space in VALUE causes the next word to be checked for");
    _print_n("\talias substitution when the alias is expanded.");
    _print_n(" ");
    _print_n("\tExit Status:");
    _print_n("\talias returns true unless a NAME is supplied for which");
    _print_n("\tno alias has been defined.");
}

/**
 * 
*/
void hp_env()
{
    _print_n("♥ Display every environmental variable ♥");
}