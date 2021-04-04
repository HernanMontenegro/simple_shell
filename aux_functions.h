#ifndef AUX_FUNCTIONS_H
#define AUX_FUNCTIONS_H

/* Split functions */
char **_split(char *, char *c);
int calc_lines(char *, char *c);
void free_split(char **splitted);
int check_split_line(char *s, int i, char *c, int *bool_commas, int *type_commas);

/* ==========Prototypes========== */
/* aux_f1.c */
void *_calloc(char *p, int size);
int _strlen(char *buff);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/* Empty Slot */
/* Empty Slot */

/* aux_f2.c */
char *_strcpy(char *src);
char *int_to_str(int n);
int _strcmp(char *s1, char *s2);
/* Empty Slot */
/* Empty Slot */

/* aux_f3.c */
void free_list(envs_list *head);
envs_list *add_node_end(envs_list **, char *, char *, int, int, int);
envs_list *generate_var_nodes(char *str, int *tot_size);
int check_var_delim(char c);
void gen_var_content(envs_list *head);

/* aux_f4.c */
int calc_var_space(envs_list *head, int tot_size);
char *var_big_bang(envs_list *head, char *str, int tot_size);
/* ==============================  */

#endif
