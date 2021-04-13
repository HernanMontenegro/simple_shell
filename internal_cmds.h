#ifndef INTERNAL_CMDS_H
#define INTERNAL_CMDS_H

/* ==========Prototypes========== */
/* in_f1.c */
void cmd_exit(int ac, char **av, char ***env, char ***alias);
void cmd_env(int ac, char **av, char ***env, char ***alias);
void cmd_setenv(int ac, char **av, char ***env, char ***alias);
void cmd_unsetenv(int ac, char **av, char ***env, char ***alias);
void cmd_cd(int ac, char **av, char ***env, char ***alias);

/* in_f2.c */
void cmd_alias(int ac, char **av, char ***env, char ***alias);
int get_index_alias(char *str, char ***alias);
void cmd_help(int ac, char **av, char ***env, char ***alias);
/* EMPTY SLOT */
/* EMPTY SLOT */

/* ==============================  */

#endif