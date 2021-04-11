#ifndef INTERNAL_CMDS_H
#define INTERNAL_CMDS_H

/* ==========Prototypes========== */
/* in_f1.c */
void cmd_exit(int ac, char **av);
void cmd_env(__attribute__((unused)) int ac,__attribute__((unused)) char **av);
void cmd_setenv(int ac, char **av);
void cmd_unsetenv(int ac, char **av);
void cmd_cd(int ac, char **av);

/* in_f2.c */
void cmd_alias(int ac, char **av);
int get_index_alias(char *str);
void cmd_help(int ac, char **av);
/* EMPTY SLOT */
/* EMPTY SLOT */

/* ==============================  */

#endif