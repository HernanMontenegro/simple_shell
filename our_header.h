#ifndef OUR_HEADER_H
#define OUR_HEADER_H

/* Globals varabols */
extern int last_child_ret;
extern char **global_env;

/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

/* Our own libraries */
#include "structs.h"
#include "aux_functions.h"

/* Getline Protptyoes */
int _getline(char **fill, int *n, int where_read);
char *add_aux_to_fill(char *fill, char *aux, int aux_size);

/* Simple Shell Prototypes  */
int infinite_loop(int fd, int read_site);

/* syntax_manager.c */
int syntax_manager(char **input);
char *delete_comments(char *str);
char *variable_translator(char *str);

#endif /* OUR_HEADER_H */
