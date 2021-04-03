#include "our_header.h"

int localize_cmd(char *str)
{
	int i;
	char **baby_av;

	baby_av = split_args(str);

	printf("Argumentos: {");
	for (i = 0; baby_av[i] != NULL; i++)
	{
		printf("%s", baby_av[i]);
		if (baby_av[i + 1] != NULL)
		{
			printf(", ");
		}
	}
	printf("}\n");

	free_split(baby_av);
	return (0); /* POR AHORA */
}

/**
* calc_lines - calculate the amount of times it found a char
* @s: the str given
* @c: the char to find
* -----------------------------------------
* Return: the number of times that character has been found
*/
char **split_args(char *s)
{
	int args_i, i = 0, j;
	int args_count = calc_args(s);
	char **res;
	char *ram;
	int bool_commas = 0;

	res = malloc((args_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);

	for(args_i = 0; args_i < args_count; args_i++)
	{
		for (j = 0; s[i + j] != '\0'; j++)
		{
			if (s[i + j] == ' ')
			{
				if (!bool_commas)
					break;
			}
			else if (s[i + j] == '"' && s[(i + j) - 1] != '\\')
			{
				if (bool_commas)
					bool_commas = 0;
				else
					bool_commas = 1;
			}
		}

		ram = malloc((j + 1) * sizeof(char));
		if (ram == NULL)
		{
			for (; args_i > 0; args_i--)
				free(res[args_i]);
			free(res);
			return (NULL);
		}

		bool_commas = 0;

		for (j = 0; s[i] != '\0'; i++, j++)
		{
			if (s[i] == ' ')
			{
				if (!bool_commas)
					break;
			}
			else if (s[i] == '"' && i != 0 && s[i - 1] != '\\')
			{
				if (bool_commas)
					bool_commas = 0;
				else
					bool_commas = 1;
			}

			ram[j] = s[i];
		}
		ram[j] = '\0';
		i++;

		res[args_i] = ram;
	}

	res[args_i] = NULL;
	return (res);
}

/**
* calc_lines - calculate the amount of times it found a char
* @s: the str given
* @c: the char to find
* -----------------------------------------
* Return: the number of times that character has been found
*/
int calc_args(const char *s)
{
	int i;
	int line = 1;
	int bool_commas = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
		{
			if (!bool_commas)
				line++;
		}
		else if (s[i] == '"' && s[i - 1] != '\\')
		{
			if (bool_commas)
				bool_commas = 0;
			else
				bool_commas = 1;
		}

	}

	return (line);
}
