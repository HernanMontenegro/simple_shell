#ifndef AUX_FUNCTIONS_H
#define AUX_FUNCTIONS_H

/* _splits1.c */
char **_split(char *, char *c);
int calc_lines(char *, char *c);
void free_split(char **splitted);
int check_split_line(char *, int, char *, int *, int *);
int remove_commas(char **uwu);

/* _splits2.c */
void comms_pross(char *, int *, int *, int *, int *);
/* EMPTY SLOT */
/* EMPTY SLOT */
/* EMPTY SLOT */
/* EMPTY SLOT */

/* ==========Prototypes========== */
/* aux_f1.c */
void *_calloc(char *p, int size);
int _strlen(char *buff);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_getenv(char *env_name, char **env);
int _atoi(char *s);

/* aux_f2.c */
char *_strcpy(char *src);
char *int_to_str(int n);
int _strcmp(char *s1, char *s2);
char *_strcon(char *str1, char *str2);
int p_strlen(char **buff);

/* aux_f3.c */
void free_list(envs_list *head);
envs_list *add_node(envs_list **, char *, char *, int, int, int);
envs_list *generate_var_nodes(char *str, int *tot_size, char ***env);
int check_var_delim(char c);
void gen_var_content(envs_list *head, char ***env);

/* aux_f4.c */
int calc_var_space(envs_list *head, int tot_size);
char *var_big_bang(envs_list *head, char *str, int tot_size);
char **copy_pstr(char **buff);
char **p_realloc(char **buff, unsigned int old_size, unsigned int new_size);
int _print(char *str);

/* aux_f5.c */
int get_env_index(char *env_name, char **env);
void _print_n(char *str);
char **create_start_alias();
char **change_command_alias(char **baby_av, char **alias);
char **p_strcon(char **p, char **p2);

/* aux_f6.c */
int str_char_check(char *str, char c);
int parent_wait(int child_pid, int *status, char ***env);
void _magic(int ac, char **av, char ***env, char ***alias);
void _setenv(char *name, char *value, char ***env);
void counter_plus_plus(char ***env);

/* aux_f7.c */
char *_super_con_err(char *baby_av, char ***env);
/* empty slot */
/* empty slot */
/* empty slot */
/* empty slot */

/* ==============================  */
#endif
