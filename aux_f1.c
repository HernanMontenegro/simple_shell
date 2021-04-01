#include "our_header.h"

/**
* _calloc - request a space in memory and assign to 0 each one
* @p: pointer to set
* @size: amount of space to reserve
* ----------------------------------------------
* Return: void
*/
void *_calloc(char *p, int size)
{
	int i;

	p = malloc(size);
	if (!p)
		return (NULL);

	for (i = 0; i < size; i++)
		p[i] = 0;

	return (p);
}

/**
* _strlen - counts the length of a string
* @buff: the buffer pointer
* ---------------------------------
* Return: the length of the string
*/
int _strlen(char *buff)
{
	int len;

	if (!buff)
		return (0);
	for (len = 0; buff[len] != '\0'; len++)
		; /* Cursed  */

	return (len);
}

/**
* _realloc - re size array
* @ptr: string
* @old_size: int
* @new_size: uns int
*
* Return: void pointer
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
		for (i = 0; i < new_size; i++)
			p[i] = 0;
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

/**
* _split - splits a string with by a specific char
* @s: the char pointer to be splitted
* @c: the char to delimitate
* ----------------------------------
* Return: a pointer to a pointer with the splitted str
*/
char **_split(const char *s, char c)
{
	int line_i, i = 0, j;
	int line_count = calc_lines(s, c);
	char **res;
	char *ram;

	res = malloc((line_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);

	for (line_i = 0; line_i < line_count; line_i++)
	{
		for (j = 0; s[i + j] != c && s[i + j] != '\0'; j++)
		{
 		}

		ram = malloc((j + 1) * sizeof(char));
		if (ram == NULL)
		{
			for (; line_i > 0; line_i--)
				free(res[line_i]);
			free(res);
			return (NULL);
		}

		for (j = 0; s[i] != c && s[i] != '\0'; i++, j++)
			ram[j] = s[i];
		ram[j] = '\0';
		i++;

		res[line_i] = ram;
	}
	res[line_i] = NULL;

	return (res);
}

/**
* calc_lines - 
*
*
*/
int calc_lines(const char *s, char c)
{
	int i;
	int line = 1;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			line++;
	}

	return (line);
}
