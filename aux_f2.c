#include "our_header.h"

/**
* _strcpy - copies a string
* @src: the source string
* @dest: the destination string
*/
char *_strcpy(char *src)
{
	int i;
	int src_len = _strlen(src) + 1;
	char *dest;

	dest = malloc(src_len * sizeof(char));
	if (!dest)
		return (NULL);

	for (i = 0; i < (src_len - 1); i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * int_to_str - convert an int to a string
 * @n: the number given
 * ----------------------------------
 * Return: the new string
*/
char *int_to_str(int n)
{
	char *res = NULL;
	int i, len = 0, div = 1, negative = 0;

	if (n < 0)
	{
		len++;
		n *= -1;
		negative = 1;
	}

	for (i = 0; (n / div) > 9; i++, len++)
		div *= 10;
	len++;

	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);

	if (negative == 1)
	{
		i = 1;
		res[0] = '-';
	}
	else
		i = 0;

	for (; i < len; i++)
	{
		res[i] = ((n / div) % 10) + '0';
		div /= 10;
	}
	res[i] = '\0';

	return (res);
}

/**
 *_strcmp - caracol
 *@s1: *
 *@s2: *
 *
 *Return: *
*/
int _strcmp(char *s1, char *s2)
{
	int i, s1C = _strlen(s1), s2C = _strlen(s2), con = 0, ret = 0;
	if (s1C > s2C)
		con = s1C;
	else
		con = s2C;
	for (i = 0; i < con; i++)
	{
		ret = s1[i] - s2[i];
		if (ret != 0)
			break;
	}
	return (ret);
}

/**
 *_strcmp - caracol
 *@s1: *
 *@s2: *
 *
 *Return: *
*/
char *_strcon(char *str1, char *str2)
{
		int i = 0, j = 0, len = 0;
		char *aux;

		len = _strlen(str1) + _strlen(str2);
		aux = malloc((len + 1) * sizeof(char));

		for (i = 0; str1 != NULL && str1[i] != '\0'; i++)
		        aux[i] = str1[i];

		for (j = 0; str2 != NULL && str2[j] != '\0'; i++, j++)
		        aux[i] = str2[j];
		aux[i] = '\0';

		return (aux);
}