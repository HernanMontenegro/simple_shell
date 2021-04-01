#include "our_header.h"

/**
* free_split - frees a splitted string
* @splitted: the splitted string
* @line: the lines to split
*/
void free_split(char **splitted)
{
	int i;

	for (i = 0; splitted && splitted[i] != NULL; i++)
		free(splitted[i]);
	free(splitted);
}

/**
* _strcpy - copies a string
* @src: the source string
* @dest: the destination string
*/
void _strcpy(char *src, char *dest)
{
	int i;
	int src_len = _strlen(src) + 1;

	dest = malloc(src_len * sizeof(char));
	if (!dest)
		return;

	for (i = 0; i < src_len; i++)
		dest[i] = src[i];
}
