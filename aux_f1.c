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
* ---------------------------------
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
 * _getenv - Get the content of an env var
 * @env_name: the name of the env var
 * @env: global env variables
 * ---------------------------------------
 * Return: string env var content
 */
char *_getenv(char *env_name, char **env)
{
	int i;
	int bool = 0;
	char **aux = NULL;
	char *save = NULL;

	for (i = 0; env && env[i] != NULL; i++)
	{
		bool = 0;
		aux = _split(env[i], "=");

		/* Iterate till finding the var name we want */
		if (_strcmp(aux[0], env_name) == 0)
		{
			bool = 1;
			break;
		}

		free_split(aux);
	}

	if (bool == 0)
		return (NULL);

	save = _strcpy(aux[1]);
	free_split(aux);

	/* Put the var content in the str directly */
	return (save);
}

/**
 * _atoi - convert a string to it's integer value
 * @s: the string given
 * ------------------------------------
 * Return: void
 */
int _atoi(char *s)
{
	int res = 0, sign = 1, i = 0;
	int len = _strlen(s);

	for (i = (len - 1); i >= 0; i--)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			res += (s[i] - '0') * sign;
			sign *= 10;
		}
	}

	if (s[0] == '-')
		res = res * -1;

	return (res);
}
