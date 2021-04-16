#ifndef OUR_HEADER_H
#define OUR_HEADER_H

/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <limits.h>

/* Our own libraries */
#include "structs.h"
#include "aux_functions.h"
#include "directors_cut.h"
#include "internal_cmds.h"
#include "help.h"

/* Getline Protptyoes */
int _getline(char **fill, int *n, int where_read);
char *add_aux_to_fill(char *fill, char *aux, int aux_size);

/* Simple Shell Prototypes  */
/* function main */
int infinite_loop(int fd, int, char ***env, char ***alias, char ***o_en);
/* Empty Slot */
/* Empty Slot */
/* Empty Slot */


/* syntax_manager.c */
int syntax_manager(char **inp, int, char ***env, char ***alias, char ***o_en);
char *delete_comments(char *str);
char *variable_translator(char *str, char ***env, char ***o_en);
int or_operat(char *str, char ***env, char ***alias, char ***o_en);
int and_operat(char *str, char ***env, char ***alias, char ***o_en);

/* pre_launch.c  */
int localize_cmd(char *str, char ***env, char ***alias, char ***o_en);
char **clean_arg(char **argv);
int built_in_cmd(char **baby_av, char ***env, char ***alias, char ***o_en);
int external_cmd(char **baby_av, char ***env, char ***o_en);
char *serch_path(char *str, char ***env);


#endif /* OUR_HEADER_H */
