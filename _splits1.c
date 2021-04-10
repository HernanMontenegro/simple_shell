#include "our_header.h"

/**
* _split - splits a string with by a specific char
* @s: the char pointer to be splitted
* @c: the char to delimitate
* ----------------------------------
* Return: a pointer to a pointer with the splitted str
*/
char **_split(char *s, char *c)
{
	int line_i, i = 0, j;
	int line_count;
	char **res;
	char *ram;
	int bool_commas = -1, type_commas = 0;

	line_count = calc_lines(s, c);
	res = malloc((line_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	for (line_i = 0; line_i < line_count; line_i++)
	{
		for (j = 0; s[i + j] != '\0'; j++)
		{
			if (check_split_line(s, (i + j), c, &bool_commas, &type_commas))
				break;
		}
		ram = malloc((j + 1) * sizeof(char));
		if (ram == NULL)
		{
			for (; line_i > 0; line_i--)
				free(res[line_i]);
			free(res);
			return (NULL);
		}
		bool_commas = -1;
		for (j = 0; s[i] != '\0'; i++, j++)
		{
			if (check_split_line(s, i, c, &bool_commas, &type_commas))
				break;
			ram[j] = s[i];
		}
		ram[j] = '\0';
		i = i + _strlen(c);
		res[line_i] = ram;
	}
	res[line_i] = NULL;
	if (!(remove_commas(res)))
		free_split(res);
	return (res);
}

/**
* calc_lines - calculate the amount of times it found a char
* @s: the str given
* @c: the char to find
* -----------------------------------------
* Return: the number of times that character has been found
*/
int calc_lines(char *s, char *c)
{
	int i;
	int line = 1;
	int bool_comm = -1, type_commas = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (check_split_line(s, i, c, &bool_comm, &type_commas))
			line++;
	}
	return (line);
}

/**
 * check_split_line - check the line syntax with commas or not
 * @s: string to check
 * @i: index of the string
 * @c: string to delimitate
 * @bool_comm: the string has commas?
 * @type_comm: which type of commas has te string?
 * -----------------------------------------------------------
 * Return: 1 if the string has commas, 0 if not
*/
int check_split_line(char *s, int i, char *c, int *bool_comm, int *type_comm)
{
	int j;
	int bool = 0, next_commas = 0, ret = 0;

	if (s[i] == '"' || s[i] == '\'')
	{
		if (!(i != 0 && s[i - 1] == '\\'))
			comms_pross(s, bool_comm, &i, &next_commas, type_comm);
	}
	for (j = 0; c[j] != '\0'; j++)
	{
		if (s[i + j] == c[j])
			bool = 1;
		else
		{
			bool = 0;
			break;
		}
	}
	if (bool == 1)
	{
		if ((*bool_comm) == -1)
			ret = 1;
	}
	return (ret);
}

/**
* free_split - frees a splitted string
* @splitted: the splitted string
* ---------------------------------------
*/
void free_split(char **splitted)
{
	int i;

	if (!splitted)
		return;

	for (i = 0; splitted && splitted[i] != NULL; i++)
		free(splitted[i]);
	free(splitted);

	splitted = NULL;
}

/**
* remove_commas - remove commas in the input string
* @uwu: the splitted string
* ---------------------------------------
* Return: 1 if everything works, 0 if not
*/
int remove_commas(char **uwu)
{
	int i, j, k;
	int len;
	char *aux;

	for (i = 0; uwu[i] != NULL; i++)
	{
		if (uwu[i][0] == '\'' || uwu[i][0] == '"')
		{
			len = _strlen(uwu[i]);
			len -= 2;

			aux = malloc((len + 1) * sizeof(char));
			if (!aux)
				return (0);

			for (j = 1, k = 0; uwu[i][j] != '\0'; j++)
			{
				if (uwu[i][j + 1] != '\0')
					aux[k++] = uwu[i][j];
			}
			aux[k] = '\0';

			free(uwu[i]);
			uwu[i] = aux;
		}
	}

	return (1);
}
