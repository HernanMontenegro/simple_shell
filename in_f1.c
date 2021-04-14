#include "our_header.h"

/**
 * cmd_exit - Exit internal command call advertiser
 * @ac: Argument count
 * @av: Arguments array
 * @env: global env variables
 * @alias: global alias variable
 * ----------------------------------------
 */
void cmd_exit(int ac, char **av, char ***env, char ***alias)
{
	char *aux = NULL, *aux_error = NULL;

	_magic(ac, av, env, alias);

	if (ac == 2)
	{
		if (_atoi(av[1]) < 0 || _atoi(av[1]) > 255)
		{
			aux_error = _super_con_err("exit", env);
			aux = _strcon(aux_error, ": Illegal number: ");
			free(aux_error);
			aux_error = _strcon(aux, av[1]);
			free(aux);
			_print_2_n(aux_error);
			free(aux_error);
			_setenv("last_child_ret", "2", env);
			return;
		}
		_setenv("abort_indicator_status", av[1], env);
	}
	else
	{
		aux = _getenv("last_child_ret", *env);
		_setenv("abort_indicator_status", aux, env);
		free(aux);
	}

	_setenv("abort_indicator", "1", env);
	_setenv("last_child_ret", "0", env);
}

/**
 * cmd_env - Manage the env built-in command
 * @ac: Argument count
 * @av: Arguments array
 * @env: global env variables
 * @alias: global alias variable
 * ----------------------------------------
 */
void cmd_env(int ac, char **av, char ***env, char ***alias)
{
	int i;
	char *cannon_meat = NULL;

	_magic(ac, av, env, alias);

	for (i = 0; (*env)[i] != NULL; i++)
	{
		cannon_meat = _strcon((*env)[i], "\n");
		_print(cannon_meat);
		free(cannon_meat);
	}
}

/**
 * cmd_setenv - Switch the value or create a new env var
 * @ac: arguments count
 * @av: arguments array
 * @env: global env variables
 * @alias: global alias variable
 * ------------------------------------------
 */
void cmd_setenv(int ac, char **av, char ***env, char ***alias)
{
	int global_env_len = 0, target_i = 0;
	char *target_env = NULL, *aux1 = NULL, *aux2 = NULL, *aux3 = NULL;

	_magic(ac, av, env, alias);

	if (ac > 3)
	{
		_print("Too many arguments\n");
		_setenv("last_child_ret", "-1", env);
		return;
	}
	else if (ac == 2)
		aux3 = _strcpy("");
	else if (ac == 3)
		aux3 = _strcpy(av[2]);
	else
	{	_print("Poor arguments\n");
		_setenv("last_child_ret", "-1", env);
		return;	
	}

	/* look if exist env var */
	target_env = _getenv(av[1], *env);
	target_i = get_env_index(av[1], *env);

	aux1 = _strcon(av[1], "=");
	aux2 = _strcon(aux1, aux3);
	free(aux1);
	free(aux3);

	if (target_env)
	{
		free((*env)[target_i]);
		(*env)[target_i] = aux2;
	}
	else
	{
		global_env_len = p_strlen(*env);
		*env = p_realloc(*env, global_env_len, global_env_len + 2);

		(*env)[global_env_len] = aux2;
		(*env)[global_env_len + 1] = NULL;
	}
	free(target_env);

	_setenv("last_child_ret", "0", env);
}

/**
 * cmd_unsetenv - Remove a previous setted environmental var
 * @ac: arguments count
 * @av: arguments array
 * @env: global env variables
 * @alias: global alias variable
 * ------------------------------------------
 */
void cmd_unsetenv(int ac, char **av, char ***env, char ***alias)
{
	int i, j;
	char **curr_env = NULL, **new_global_env = NULL;
	char *target_env = NULL;

	_magic(ac, av, env, alias);
	if (ac != 2)
	{
		_print("Too many arguments\n");
		_setenv("last_child_ret", "-1", env);
		return;
	}
	target_env = _getenv(av[1], *env);
	if (!target_env)
	{
		_print("404: Environmental variable not found\n");
		_setenv("last_child_ret", "-1", env);
		return;
	}
	free(target_env);
	new_global_env = malloc((p_strlen(*env) + 1) * sizeof(char *));
	if (!new_global_env)
	{
		_setenv("last_child_ret", "-1", env);
		return;
	}
	for (i = 0, j = 0; (*env)[i] != NULL; i++)
	{
		curr_env = _split((*env)[i], "=");
		if (_strcmp(curr_env[0], av[1]) == 0)
		{
			free_split(curr_env);
			continue;
		}
		new_global_env[j++] = _strcpy((*env)[i]);
		free_split(curr_env);
	}
	free_split(*env);
	new_global_env[j] = NULL;
	*env = new_global_env;
	_setenv("last_child_ret", "0", env);
}

/**
 * cmd_cd - CD internal command call advertiser
 * @ac: Argument count
 * @av: Arguments array
 * @env: global env variables
 * @alias: global alias variable
 * ----------------------------------------
 */
void cmd_cd(int ac, char **av, char ***env, char ***alias)
{
	int len_buff = 0;
	char *path = NULL, *path_old = NULL;

	_magic(ac, av, env, alias);
	if (ac == 1)
		path = _getenv("HOME", *env);
	else if (ac > 2)
	{
		_print("Too many arguments\n");
		_setenv("last_child_ret", "-1", env);
		return;
	}
	else if (ac == 2)
	{
		if (av[1][0] == '-')
			path = _getenv("OLDPWD", *env);
		else
			path = _strcpy(av[1]);
	}
	if (chdir(path) == -1)
	{
		_setenv("last_child_ret", "1", env);
		free(path);
		perror("Error");
		return;
	}
	path_old = _getenv("PWD", *env);
	len_buff = _strlen(path) + _strlen(path_old) + 10;
	free(path);
	path = _calloc(path, len_buff);
	getcwd(path, len_buff);
	_setenv("OLDPWD", path_old, env);
	_setenv("PWD", path, env);
	if (ac > 1 && av[1][0] == '-')
		_print_n(path);
	free(path_old);
	free(path);
	_setenv("last_child_ret", "0", env);
}
