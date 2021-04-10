#include "our_header.h"

/**
* _getline - read an entire line
* @fill: the variable to fill with the line
* @n: the bytes tried to read
* @where_read: the file descriptor
* ----------------------------------------
* Return: -1 if fails, the readed bytes
*/
int _getline(char **fill, int *n, int where_read)
{
	char *aux = NULL;
	int readed_bytes = 0, total_bytes = 0;
	int buff_size = 120;

	*n = buff_size;
	while (1)
	{
		aux = NULL;
		aux = _calloc(aux, buff_size);
		if (!aux)
			return (-1);

		readed_bytes = read(where_read, aux, buff_size);
		if (readed_bytes == -1)
		{
			free(aux);
			return (-1);
		}

		if (aux != NULL)
			*fill = add_aux_to_fill(*fill, aux, readed_bytes);

		total_bytes += readed_bytes;

		if (readed_bytes == 0 || readed_bytes < buff_size)
			break;

		*n += buff_size;
		free(aux);
	}
	free(aux);

	return (total_bytes);
}

/**
* add_aux_to_fill - add aux to our fill in _getline
* @fill: the fill char pointer
* @aux: the aux char pointer
* @aux_size: the size of aux
* --------------------------------------
* Return: the filled char pointer
*/
char *add_aux_to_fill(char *fill, char *aux, int aux_size)
{
	int fill_len;
	int new_size;
	int i, j;

	fill_len = _strlen(fill);
	new_size = fill_len + aux_size + 1;
	fill = _realloc(fill, fill_len, new_size);

	for (i = fill_len, j = 0; i < (new_size - 1); i++, j++)
		fill[i] = aux[j];
	fill[i] = '\0';

	return (fill);
}
