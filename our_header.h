#ifndef OUR_HEADER_H
#define OUR_HEADER_H

/* Globals varabols */
extern int last_child_ret;

/* Libraries to use */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#include "aux_functions.h"
#include "lists.h"

/**
* struct in_com - internal commands
* @command: the command char pointer
* @f: the pointer to a function
* -----------------------------------------
* Description: Manages the internal commands
*/
typedef struct in_com
{
	char *command;
	void (*f)(int ac, char **av);

} internal_commands;

/* Prototypes  */
int _getline(char **fill, int *n, int where_read);
char *add_aux_to_fill(char *fill, char *aux, int aux_size);
int infinite_loop(int fd, int read_site);
char *variable_translator(char *str);

#endif /* OUR_HEADER_H */
