#ifndef OUR_HEADER_H
#define OUR_HEADER_H

/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* Our own libraries */
#include "structs.h"
#include "aux_functions.h"
#include "internal_cmds.h"
#include "help.h"

/* Getline Protptyoes */
int _getline(char **fill, int *n, int where_read);
char *add_aux_to_fill(char *fill, char *aux, int aux_size);

/* Simple Shell Prototypes  */
/* function main */
int infinite_loop(int fd, int read_site, char ***env, char ***alias);
/* Empty Slot */
/* Empty Slot */
/* Empty Slot */


/* syntax_manager.c */
int syntax_manager(char **input, int fd, char ***env, char ***alias);
char *delete_comments(char *str);
char *variable_translator(char *str, char ***env);
int or_operat(char *str, char ***env, char ***alias);
int and_operat(char *str, char ***env, char ***alias);

/* pre_launch.c  */
int localize_cmd(char *str, char ***env, char ***alias);
char **clean_arg(char **argv);
int built_in_cmd(char **baby_av, char ***env, char ***alias);
int external_cmd(char **baby_av, char ***env);
char *serch_path(char *str, char ***env);


#endif /* OUR_HEADER_H */
