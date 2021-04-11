#include "our_header.h"

/**
 * cmd_exit - Exit internal command call advertiser
 * @ac: Argument count
 * @av: Arguments array
 * ----------------------------------------
 */
void cmd_exit(int ac, char **av)
{
	abort_indicator = 1;

	if (ac == 2)
		abort_indicator_status = _atoi(av[1]);
	else
		abort_indicator_status = 0;
}

/**
 * cmd_env - Manage the env built-in command
 * @ac: Argument count
 * @av: Arguments array
 * ----------------------------------------
 */
void cmd_env(__attribute__((unused)) int ac, __attribute__((unused)) char **av)
{
	int i;
	char *cannon_meat = NULL;

	for (i = 0; global_env[i] != NULL; i++)
	{
		cannon_meat = _strcon(global_env[i], "\n");
		_print(cannon_meat);
		free(cannon_meat);
	}
}

/**
 * cmd_setenv - Switch the value or create a new env var
 * @ac: arguments count
 * @av: arguments array
 * ------------------------------------------
 */
void cmd_setenv(int ac, char **av)
{
	int global_env_len = 0, target_i = 0;
	char *target_env = NULL, *aux1 = NULL, *aux2 = NULL;

	if (ac != 3)
	{
		_print("Too many arguments\n");
		last_child_ret = -1;
		return;
	}

	/* look if exist env var */
	target_env = _getenv(av[1]);
	target_i = get_env_index(av[1]);

	aux1 = _strcon(av[1], "=");
	aux2 = _strcon(aux1, av[2]);
	free(aux1);

	if (target_env)
	{
		free(global_env[target_i]);
		global_env[target_i] = aux2;
	}
	else
	{
		global_env_len = p_strlen(global_env);
		global_env = p_realloc(global_env, global_env_len, global_env_len + 2);

		global_env[global_env_len] = aux2;
		global_env[global_env_len + 1] = NULL;
	}
	free(target_env);

	last_child_ret = 0;
}

/**
 * cmd_unsetenv - Remove a previous setted environmental var
 * @ac: arguments count
 * @av: arguments array
 * ------------------------------------------
 */
void cmd_unsetenv(int ac, char **av)
{
	int i, j;
	char **curr_env = NULL;
	char **new_global_env = NULL;
	char *target_env = NULL;

	if (ac != 2)
	{
		_print("Too many arguments\n");
		last_child_ret = -1;
		return;
	}
	target_env = _getenv(av[1]);
	if (!target_env)
	{
		_print("404: Environmental variable not found\n");
		last_child_ret = -1;
		return;
	}
	free(target_env);
	new_global_env = malloc((p_strlen(global_env) + 1) * sizeof(char *));
	if (!new_global_env)
	{
		last_child_ret = -1;
		return;
	}
	for (i = 0, j = 0; global_env[i] != NULL; i++)
	{
		curr_env = _split(global_env[i], "=");
		if (_strcmp(curr_env[0], av[1]) == 0)
		{
			free_split(curr_env);
			continue;
		}
		new_global_env[j++] = _strcpy(global_env[i]);
		free_split(curr_env);
	}
	free_split(global_env);
	new_global_env[j] = NULL;
	global_env = new_global_env;
	last_child_ret = 0;
}

/**
 * cmd_cd - CD internal command call advertiser
 * @ac: Argument count
 * @av: Arguments array
 * ----------------------------------------
 */
void cmd_cd(int ac, char **av)
{
int len_buff = 0;
char *path = NULL, *path_old = NULL;
char *e[] = {"setenv", "OLDPWD", "", NULL}, *r[] = {"setenv", "PWD", "", NULL};

	if (ac == 1)
		path = _getenv("HOME");
	else if (ac > 2)
	{
		_print("Too many arguments\n");
		last_child_ret = -1;
		return;
	}
	else if (ac == 2)
	{
		if (av[1][0] == '-')
			path = _getenv("OLDPWD");
		else
			path = _strcpy(av[1]);
	}
	if (chdir(path) == -1)
	{
		last_child_ret = 1;
		free(path);
		perror("Error");
		return;
	}
	path_old = _getenv("PWD");
	len_buff = _strlen(path) + _strlen(path_old) + 10;
	free(path);
	path = _calloc(path, len_buff);
	getcwd(path, len_buff);
	e[2] = path_old;
	cmd_setenv(3, e);
	r[2] = path;
	cmd_setenv(3, r);
	if (ac > 1 && av[1][0] == '-')
		_print_n(path);
	free(path_old);
	free(path);
	last_child_ret = 0;
}
