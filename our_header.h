#ifndef OUR_HEADER_H
#define OUR_HEADER_H

/* Globals varabols */
extern int last_child_ret;
extern char **global_env;

extern int abort_indicator;
extern int abort_indicator_status;

/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

/* Our own libraries */
#include "structs.h"
#include "aux_functions.h"
#include "internal_cmds.h"

/* Getline Protptyoes */
int _getline(char **fill, int *n, int where_read);
char *add_aux_to_fill(char *fill, char *aux, int aux_size);

/* Simple Shell Prototypes  */
/* function main */
int infinite_loop(int fd, int read_site);
/* Empty Slot */
/* Empty Slot */
/* Empty Slot */


/* syntax_manager.c */
int syntax_manager(char **input);
char *delete_comments(char *str);
char *variable_translator(char *str);
int or_operat(char *str);
int and_operat(char *str);

/* pre_launch.c  */
int localize_cmd(char *str);
char **clean_arg(char **argv);
int built_in_cmd(char **baby_av);
int external_cmd(char **baby_av);
char *serch_path(char *str);


#endif /* OUR_HEADER_H */
