#ifndef OUR_HEADER_H
#define OUR_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int _getline(char *fill, int *n, int where_read);
void *_calloc(char *p, int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *buff);
void add_aux_to_fill(char *fill, char *aux, int aux_size);

#endif /* OUR_HEADER_H */
