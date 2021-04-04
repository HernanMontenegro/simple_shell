#include "our_header.h"

/**
 * localize_cmd - Localize if the input is a command
 * @str: the string to check
 * ----------------------------------
 * Return: command exit status if is a command, 1 if not
 */ 
int localize_cmd(char *str)
{
	char **baby_av;

	baby_av = _split(str, " ");
	baby_av = clean_arg(baby_av);

	if (!(built_in_cmd(baby_av)))
	{
		if (!(external_cmd(baby_av)))
		{
			printf("Comando no encontrado\n");
		}
	}

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


int built_in_cmd(char **baby_av)
{
	int i = 0, ac = 0;
	internal_commands list_com[] = {
			{"exit", cmd_exit},
			{NULL, NULL}
	};

	for (ac = 0; baby_av[ac] != NULL; ac++)
			; /* UwU Cursed */

	for (i = 0; list_com[i].command != NULL; i++)
	{
		if (_strcmp(baby_av[0], list_com[i].command) == 0)
		{
			list_com[i].f(ac, baby_av);
			return (1);
		}
	}

	return (0);
}

int external_cmd(char **baby_av)
{
	char *aux = NULL;
	
	aux = serch_path(baby_av[0]);
	if(!aux)
		return (0);
	free(baby_av[0]);
	baby_av[0] = aux;


	printf("CREAER HIJO: %s\n", baby_av[0]);
	/*HIJO*/

	return (1);
}

char *serch_path(char *str)
{
	int i = 0;
	char **path_list;
	struct stat st;
	char *path = NULL;
	char *aux = NULL;
	char *complete_cmd = NULL;

	aux = _getenv("PATH");
	path_list = _split(aux, ":");
	free(aux);

	for (i = 0; path_list[i] != NULL; i++)
	{
		path = _strcon("/", str);
		complete_cmd = _strcon(path_list[i], path);
		free(path);

		if (stat(complete_cmd, &st) == 0)
		{
			free_split(path_list);
			return (complete_cmd);
		}

		free(complete_cmd);
	}
	free_split(path_list);

	if (stat(str, &st) == 0)
	    return (_strcpy(str));

	return (NULL);
}