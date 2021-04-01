#include "our_header.h"

/**
*
*
*/
int _getline(char *fill, int *n, int where_read)
{
	char *aux = NULL;
	int readed_bytes = 0, total_bytes = 0;
	int buff_size = 120;

	*n = 0;
	while (1)
	{
		aux = NULL;
		aux = _calloc(aux, buff_size);
		if (!aux)
			return (-1);
		readed_bytes = read(where_read, aux, buff_size);
		if (readed_bytes == -1)
			return (-1);

		add_aux_to_fill(fill, aux, readed_bytes);

		if (readed_bytes == 0 || readed_bytes < buff_size)
			break;

		total_bytes += readed_bytes;
		*n += buff_size;
		free(aux);
	}

	return (readed_bytes);
}

void *_calloc(void *p, int size)
{
	int i;

	p = malloc(size);
	if (!p)
		return (NULL);

	for (i = 0; i < size; i++)
		p[i] = 0;

	return (p);
}


void add_aux_to_fill(char *fill, char *aux, int aux_size)
{
	int fill_len = _strlen(fill);
	int new_size = fill_len + aux_size;
	int i, j;

	fill = _realloc(fill, fill_len, new_size);

	for (i = fill_len, j = 0; i < new_size; i++, j++)
		fill[i] = aux[j];
}

int _strlen(char *buff)
{
	int len;

	for (len = 0; buff[len]; len++);

	return (len);
}

/**
 *_realloc - re size array
 *@ptr: string
 *@old_size: int}
 *@new_size: uns int
 *
 *Return: void pointer
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, cal;
	char *p;
	char *new_ptr;
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		return (p);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);
	if (new_size > old_size)
		cal = old_size;
	else
		cal = new_size;
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	new_ptr = ptr;
	for (i = 0; i < cal; i++)
		p[i] = new_ptr[i];
	free(ptr);
	return (p);
}
