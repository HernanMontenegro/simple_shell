#ifndef OUR_HEADER_H
#define OUR_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void *_calloc(void *p, int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _strlen(char *buff);
void add_aux_to_fill(char *fill, char *aux, int aux_size);

#endif /* OUR_HEADER_H */
