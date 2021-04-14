#include "our_header.h"

/**
 * cmd_alias - alias built-in command
 * @ac: argument count
 * @av: argument array
 * @env: global env variables
 * @alias: global alias variable
 * -------------------------------------
*/
void cmd_alias(int ac, char **av, char ***env, char ***alias)
{
	int i, alias_len = 0, index_alias = -1;
	char *aux = NULL, **checker = NULL;

	_magic(ac, av, env, alias);

	if (ac == 1)
		for (i = 0; (*alias)[i] != NULL; i++)
		{
			aux = _strcon("alias ", (*alias)[i]);
			_print_n(aux);
			free(aux);
		}
	for (i = 1; av[i] != NULL; i++)
	{
		checker = _split(av[i], "=");
		index_alias = get_index_alias(checker[0], alias);

		if (!checker[1] && index_alias != -1)
		{
			aux = _strcon("alias ", (*alias)[index_alias]);
			_print_n(aux);
			free(aux);
		}
		else if (index_alias != -1)
		{
			free((*alias)[index_alias]);
			(*alias)[index_alias] = _strcpy(av[i]);
		}
		else
		{
			alias_len = p_strlen(*alias);
			(*alias) = p_realloc(*alias, alias_len, alias_len + 2);
			(*alias)[alias_len] = _strcpy(av[i]);
			(*alias)[alias_len + 1] = NULL;
		}
	}
	_setenv("LAST_CHILD_RET", "0", env);
}

/**
 * get_index_alias - get index of an alias
 * @str: the alias to find the index
 * @alias: global alias variable
 * ------------------------------------
 * Return: the index of the alias, -1 if fails
*/
int get_index_alias(char *str, char ***alias)
{
	int i;
	char **aux = NULL;

	for (i = 0; (*alias)[i] != NULL; i++)
	{
		aux = _split((*alias)[i], "=");
		if (_strcmp(aux[0], str) == 0)
		{
			free_split(aux);
			return (i);
		}
		free_split(aux);
	}

	return (-1);
}

/**
 * cmd_help - alias built-in command
 * @ac: argument count
 * @av: argument array
 * @env: global env variables
 * @alias: global alias variable
 * -------------------------------------
*/
void cmd_help(int ac, char **av, char ***env, char ***alias)
{
	char *aux = NULL, *aux2 = NULL;

	_magic(ac, av, env, alias);
	if (ac == 1)
	{
		hp_help();
		return;
	}
	else if (_strcmp(av[1], "exit") == 0)
		hp_exit();
	else if (_strcmp(av[1], "cd") == 0)
		hp_cd();
	else if (_strcmp(av[1], "alias") == 0)
		hp_alias();
	else if (_strcmp(av[1], "env") == 0)
		hp_env();
	else if (_strcmp(av[1], "setenv") == 0)
		hp_setenv();
	else if (_strcmp(av[1], "unsetenv") == 0)
		hp_unsetenv();
	else
	{
		aux = _strcon("bash: help: no help topics match '", av[1]);
		aux2 = _strcon(aux, "'.");
		_print_n(aux2);
		free(aux);
		free(aux2);
	}
}
