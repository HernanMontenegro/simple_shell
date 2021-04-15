#include "our_header.h"

/**
* check_num - checks if a string is entirely with numbers
* @str: string given
* ------------------------------------------
* Return: 1 if is a string purely with numbers, 0 if not
*/
int check_num(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

/**
* _set_PWD - set only PWD in the env
* @env: global environment variables
* ------------------------------------------
*/
void _set_PWD(char ***env)
{
	char cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		_setenv("PWD", cwd, env);
	}
}

/**
* _print_2_n_extend - cut from large functions xd
* @fun: function name to use
* @str: string to print
* @n: number string to setenv
* @o_en: our global env variables
*/
void _print_2_n_extend(char *fun, char *str, char *n, char ***o_en)
{
	char *aux_error = NULL, *aux = NULL;

	aux_error = _super_con_err(fun, o_en);
	aux = _strcon(aux_error, str);
	_print_2_n(aux);
	free(aux);
	free(aux_error);

	_setenv("LAST_CHILD_RET", n, o_en);
}

/**
 * _getenv_exist - Check if an env exist
 * @env_name: env var name
 * @env: global env var name
 * ----------------------------------
 * Return: 1 if exist, 0 if not
*/
int _getenv_exist(char *env_name, char **env)
{
	int i;
	int bool = 0;
	char **aux = NULL;

	for (i = 0; env && env[i] != NULL; i++)
	{
		bool = 0;
		aux = _split(env[i], "=");

		/* Iterate till finding the var name we want */
		if (_strcmp(aux[0], env_name) == 0)
		{
			bool = 1;
			break;
		}

		free_split(aux);
	}

	return (bool);
}
