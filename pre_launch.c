#include "our_header.h"

/**
 * localize_cmd - Localize if the input is a command
 * @str: the string to check
 * ----------------------------------
 * Return: command exit status if is a command, 1 if not
 */ 
int localize_cmd(char *str)
{
	int i;
	char **baby_av;

	baby_av = _split(str, " ");
	baby_av = clean_arg(baby_av);

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
 * clean_arg - Bless the string command array given, remove all strange chars
 * @argv: the string command given
 * ---------------------------------------
 * Return: a new blessed string command, without impurities
 */ 
char **clean_arg(char **argv)
{
	int i, j;
	int len = 0;
	char **clear = NULL;

	for (i = 0; argv[i] != NULL; i++)
	{
		if (argv[i][0] != '\0')
			len++;
	}

	clear = malloc((len + 1) * sizeof(char *));
	if (!clear)
		return (NULL);

	for (i = 0, j = 0; argv[i] != NULL; i++)
	{
		if (argv[i][0] == '\0')
			free(argv[i]);
		else
		{
			clear[j] = argv[i];
			j++;
		}
	}
	clear[j] = NULL;
	free(argv);

	return (clear);
}
