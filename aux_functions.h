#ifndef AUX_FUNCTIONS_H
#define AUX_FUNCTIONS_H

/* Prototypes  */
void *_calloc(char *p, int size);
int _strlen(char *buff);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_split(const char *, char c);
int calc_lines(const char *, char c);

#endif
