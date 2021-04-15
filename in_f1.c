#include "our_header.h"

/**
 * cmd_exit - Exit internal command call advertiser
 * @ac: Argument count
 * @av: Arguments array
 * @env: global env variables
 * @alias: global alias variable
 * @o_en: our global env variables
 * ----------------------------------------
 */
void cmd_exit(int ac, char **av, char ***env, char ***alias, char ***o_en)
{
	char *aux = NULL, *aux_error = NULL;
	int calc = 0;

	_magic(ac, av, env, alias, o_en);

	if (ac == 2)
	{
		if (!(check_num(av[1])) || _atoi(av[1]) < 0 || _atoi(av[1]) > INT_MAX)
		{
			aux_error = _super_con_err("exit", o_en);
			aux = _strcon(aux_error, ": Illegal number: ");
			free(aux_error);
			aux_error = _strcon(aux, av[1]);
			free(aux);
			_print_2_n(aux_error);
			free(aux_error);
			_setenv("LAST_CHILD_RET", "2", o_en);
			return;
		}
		calc = _atoi(av[1]);
		calc = calc - ((calc / 256) * 256);
		aux = int_to_str(calc);
		_setenv("ABORT_INDICATOR_STATUS", aux, o_en);
		free(aux);
	}
	else
	{
		aux = _getenv("LAST_CHILD_RET", *o_en);
		_setenv("ABORT_INDICATOR_STATUS", aux, o_en);
		free(aux);
	}

	_setenv("ABORT_INDICATOR", "1", o_en);
	_setenv("LAST_CHILD_RET", "0", o_en);
}

/**
 * cmd_env - Manage the env built-in command
 * @ac: Argument count
 * @av: Arguments array
 * @env: global env variables
 * @alias: global alias variable
 * @o_en: our global env variables
 * ----------------------------------------
 */
void cmd_env(int ac, char **av, char ***env, char ***alias, char ***o_en)
{
	int i;
	char *cannon_meat = NULL;

	_magic(ac, av, env, alias, o_en);

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
 * @o_en: our global env variables
 * ------------------------------------------
 */
void cmd_setenv(int ac, char **av, char ***env, char ***alias, char ***o_en)
{
	int global_env_len = 0, target_i = 0;
	char *aux1 = NULL, *aux2 = NULL, *aux3 = NULL;

	_magic(ac, av, env, alias, o_en);
	if (ac > 3)
	{
		_print_2_n_extend("setenv", ": Error no more than 3 parameters", "0", o_en);
		return;
	}
	else if (ac == 3)
		aux3 = _strcpy(av[2]);
	else
	{
_print_2_n_extend("setenv", ": Error expect at least 2 parameters", "0", o_en);
		return;
	}
	target_i = get_env_index(av[1], *env);
	aux1 = _strcon(av[1], "=");
	aux2 = _strcon(aux1, aux3);
	free(aux1);
	free(aux3);
	if (_getenv_exist(av[1], *env))
	{
		free((*env)[target_i]);
		(*env)[target_i] = aux2;
	}
	else
	{
		global_env_len = p_strlen(*env);
		*env = p_realloc(*env, global_env_len, global_env_len + 2);
		if (*env == NULL)
		{
			_print_2_n_extend("setenv", ": Error changing environment variable", "1", o_en);
			return;
		}
		(*env)[global_env_len] = aux2;
		(*env)[global_env_len + 1] = NULL;
	}
	_setenv("LAST_CHILD_RET", "0", o_en);
}

/**
 * cmd_unsetenv - Remove a previous setted environmental var
 * @ac: arguments count
 * @av: arguments array
 * @env: global env variables
 * @alias: global alias variable
 * @o_en: our global env variables
 * ------------------------------------------
 */
void cmd_unsetenv(int ac, char **av, char ***env, char ***alias, char ***o_en)
{
	int i, j;
	char **curr_env = NULL, **new_global_env = NULL;
	char *target_env = NULL, *aux_error = NULL, *aux = NULL;

	_magic(ac, av, env, alias, o_en);
	if (ac != 2)
	{
		_setenv("LAST_CHILD_RET", "0", o_en);
		return;
	}
	target_env = _getenv(av[1], *env);
	if (!target_env)
	{
		aux_error = _super_con_err("unsetenv", o_en);
		aux = _strcon(aux_error, ": Error variable not found");
		_print_2_n(aux);
		free(aux);
		free(aux_error);
		_setenv("LAST_CHILD_RET", "0", o_en);
		return;
	}
	free(target_env);
	new_global_env = malloc((p_strlen(*env) + 1) * sizeof(char *));
	if (!new_global_env)
	{
		aux_error = _super_con_err("unsetenv", o_en);
		aux = _strcon(aux_error, ": Error deleting environment variable");
		_print_2_n(aux);
		_setenv("LAST_CHILD_RET", "1", o_en);
		free(aux);
		free(aux_error);
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
	_setenv("LAST_CHILD_RET", "0", o_en);
}

/**
 * cmd_cd - CD internal command call advertiser
 * @ac: Argument count
 * @av: Arguments array
 * @env: global env variables
 * @alias: global alias variable
 * @o_en: our global env variables
 * ----------------------------------------
 */
void cmd_cd(int ac, char **av, char ***env, char ***alias, char ***o_en)
{
	int len_buff = 0;
	char *path = NULL, *path_old = NULL, *aux_error = NULL, *aux = NULL;
	char cwd[PATH_MAX];

	_magic(ac, av, env, alias, o_en);
	if (ac == 1)
	{
		path = _getenv("HOME", *env);
		if (path == NULL)
		{
			_setenv("LAST_CHILD_RET", "0", o_en);
			return;
		}
	}
	else if (ac > 2)
	{
		_print("Too many arguments\n");
		_setenv("LAST_CHILD_RET", "-1", o_en);
		return;
	}
	else if (ac == 2)
	{
		if (av[1][0] == '-')
		{
			path = _getenv("OLDPWD", *env);
			if (path == NULL)
			{
				if (getcwd(cwd, sizeof(cwd)) != NULL)
				{
					_setenv("OLDPWD", cwd, env);
					_print_n(cwd);
				}
				return;
			}
		}
		else
			path = _strcpy(av[1]);
	}
	if (chdir(path) == -1)
	{
		_setenv("LAST_CHILD_RET", "2", o_en);
		
		aux_error = _super_con_err("cd", o_en);
		aux = _strcon(aux_error, ": can't cd to ");
		free(aux_error);
		aux_error = _strcon(aux, path);
		_print_2_n(aux_error);
		free(aux);
		free(aux_error);
		free(path);
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
	_setenv("LAST_CHILD_RET", "0", o_en);
}
