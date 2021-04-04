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
	int line_count = calc_lines(s, c);
	char **res;
	char *ram;
	int bool_commas = -1;

	res = malloc((line_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);

	for (line_i = 0; line_i < line_count; line_i++)
	{
		for (j = 0; s[i + j] != '\0'; j++)
		{
			if (check_split_line(s , (i + j), c, &bool_commas))
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
			if (check_split_line(s , i, c, &bool_commas))
				break;
			ram[j] = s[i];
		}
		ram[j] = '\0';
		i = i + _strlen(c);

		res[line_i] = ram;
	}
	res[line_i] = NULL;
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
	int bool_commas = -1;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (check_split_line(s , i, c, &bool_commas))
			line++;
	}

	return (line);
}

int check_split_line(char *s, int i, char *c, int *bool_commas)
{
	int j;
	int bool = 0, next_commas = 0, ret = 0;
	
	if (s[i] == '"' && s[i] == '\'')
	{
		if (!(i != 0 && s[i - 1] == '\\'))
		{
			if ((*bool_commas) == -1)
			{
				for (j = 0; s[i + j] != '\0'; j++)
				{
					if (s[j] == '"' && s[i] == '\''){
						next_commas = 1;
						break;
					}
				}
				if (next_commas)
					*bool_commas = *bool_commas * -1;
			}
			else
				*bool_commas = *bool_commas * -1;
		}
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
		if ((*bool_commas) == -1)
				ret = 1;
	}
	return (ret);
}

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