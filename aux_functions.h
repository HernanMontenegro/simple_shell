#ifndef AUX_FUNCTIONS_H
#define AUX_FUNCTIONS_H

/* ==========Prototypes========== */
/* aux_f1.c */
void *_calloc(char *p, int size);
int _strlen(char *buff);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_split(const char *, char c);
int calc_lines(const char *, char c);

/* aux_f2.c */
void free_split(char **splitted);
char *_strcpy(char *src);
char *int_to_str(int n);
int _strcmp(char *s1, char *s2);

/* syntax_manager.c */
int syntax_manager(char **input);
char *delete_comments(char *str);

/* Marvellous  */
#include "lists.h"

/* ==============================  */

#endif
