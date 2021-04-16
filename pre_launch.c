#include "our_header.h"

/**
 * localize_cmd - Localize if the input is a command
 * @str: the string to check
 * @env: global env variables
 * @alias: global alias variable
 * @o_en: our global env var
 * ----------------------------------
 * Return: command exit status if is a command, 1 if not
 */
int localize_cmd(char *str, char ***env, char ***alias, char ***o_en)
{
	char **baby_av;
	char **aux;
	char *aux_error = NULL, *aux2 = NULL;
	int ret = 0;

	baby_av = _split(str, " ");
	baby_av = clean_arg(baby_av);

	if (baby_av[0] == NULL)
	{
		free_split(baby_av);
		return (0);
	}

	aux = change_command_alias(baby_av, *alias);
	if (aux != NULL)
	{
		free_split(baby_av);
		baby_av = aux;
		baby_av = clean_arg(baby_av);
	}

	if (!(built_in_cmd(baby_av, env, alias, o_en)))
	{
		ret = external_cmd(baby_av, env, o_en);
		if (ret == 0)
		{
			aux_error = _super_con_err(baby_av[0], o_en);
			aux2 = _strcon(aux_error, ": not found\n");
			_print_2(aux2);
			free(aux2);
			free(aux_error);
			free_split(baby_av);
			return (1);
		}
	}

	free_split(baby_av);

	return (get_int_env("LAST_CHILD_RET", o_en));
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

/**
 * built_in_cmd - Built in commands manager
 * @baby_av: The cleanned baby to analize
 * @env: global env variables
 * @alias: global alias variable
 * @o_en: our global env var
 * -------------------------
 * Return: 1 if found an internal command, 0 if not
 */
int built_in_cmd(char **baby_av, char ***env, char ***alias, char ***o_en)
{
	int i = 0, ac = 0;
	internal_commands list_com[] = {
		{"exit", cmd_exit},
		{"env", cmd_env},
		{"oen", cmd_oen},
		{"setenv", cmd_setenv},
		{"unsetenv", cmd_unsetenv},
		{"cd", cmd_cd},
		{"alias", cmd_alias},
		{"help", cmd_help},
		{"uwu", cmd_uwu},
		{NULL, NULL}
	};

	for (ac = 0; baby_av[ac] != NULL; ac++)
		; /* UwU Cursed */

	for (i = 0; list_com[i].command != NULL; i++)
	{
		if (_strcmp(baby_av[0], list_com[i].command) == 0)
		{
			list_com[i].f(ac, baby_av, env, alias, o_en);
			return (1);
		}
	}

	return (0);
}

/**
 * external_cmd - External commands manager
 * @baby_av: The cleanned baby to analize
 * @env: global env variables
 * @o_en: our global env var
 * -------------------------
 * Return: 1 if found an external command, 0 if not
 */
int external_cmd(char **baby_av, char ***env, char ***o_en)
{
	char *aux = NULL, *aux2 = NULL;
	struct stat st;
	pid_t child_pid = 0;
	int status, bool = 1, output = 0;

	if (extrn_cmd_2(baby_av, &bool, &st, &aux, &aux2,
	o_en, env) == 0)
		return (0);
	if (check_dir(aux))
	{
		aux2 = int_to_str(127);
		_setenv("LAST_CHILD_RET", aux2, o_en);
		free(aux2);
		free(aux);
		return (0);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork failed");
		return (0);
	}
	if (child_pid == 0)
	{
		if (execve(aux, baby_av, *env) == -1)
			extrn_cmd_3(&aux, o_en);
	}
	else
	{
		output = parent_wait(child_pid, &status);
		aux2 = int_to_str(output);
		_setenv("LAST_CHILD_RET", aux2, o_en);
		free(aux2);
		free(aux);
		if (output == 0)
			return (1);
		return (2);
	}
	return (1);
}

/**
 * serch_path - Search if exist an executable with a specific name
 * @str: the name to find the PATH
 * @env: global env variables
 * -------------------------------------------
 * Return: The filled PATH founded, NULL otherwhise
 */
char *serch_path(char *str, char ***env)
{
	int i = 0;
	char **path_list;
	struct stat st;
	char *path = NULL;
	char *aux = NULL;
	char *complete_cmd = NULL;

	aux = _getenv("PATH", *env);
	if (aux == NULL)
		return (NULL);

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

	return (NULL);
}
