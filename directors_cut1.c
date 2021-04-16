#include "our_header.h"

/**
 * setenv_part2 - cut off from cmd_setenv
 * @tar_env: target_env
 * @tar_i: target_i
 * @av1: av[1] of setenv
 * @aux2: aux2 pointer
 * @env: global envs
 * @aux3: aux3 pointer
 * ---------------------------------------------------
*/
void setenv_part2(char **tar_env, int *tar_i, char *av1, char **aux2,
char **env, char **aux3)
{
	char *aux1 = NULL;

	*tar_env = _getenv(av1, env);
	*tar_i = get_env_index(av1, env);
	aux1 = _strcon(av1, "=");
	*aux2 = _strcon(aux1, *aux3);
	free(aux1);
}

/**
 * unsetenv_p2 - unsetenv part 2
 * @a_error: aux_error pointer
 * @o_en: our global env
 * --------------------------------------
*/
void unsetenv_p2(char **a_error, char ***o_en)
{
	char *aux = NULL;

	*a_error = _super_con_err("unsetenv", o_en);
	aux = _strcon(*a_error, ": Error variable not found");
	_print_2_n(aux);
	_setenv("LAST_CHILD_RET", "0", o_en);
	free(aux);
	free(*a_error);
}

/**
 * unsetenv_p3 - unsetenv part 2
 * @a_error: aux_error pointer
 * @o_en: our global env
 * --------------------------------------
*/
void unsetenv_p3(char **a_error, char ***o_en)
{
	char *aux = NULL;

	*a_error = _super_con_err("unsetenv", o_en);
	aux = _strcon(*a_error, ": Error deleting environment variable");
	_print_2_n(aux);
	_setenv("LAST_CHILD_RET", "1", o_en);
	free(aux);
	free(*a_error);
}

/**
 * cd_p2 - cmd_cd part 2
 * @c: char to compare
 * @path: path
 * @av1: av[1]
 * @env: global envs
 * -------------------------------
*/
void cd_p2(char c, char **path, char *av1, char ***env)
{
	char cwd[PATH_MAX];

	if (c == '-')
	{
		*path = _getenv("OLDPWD", *env);
		if (*path == NULL)
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
		*path = _strcpy(av1);
}

/**
 * cd_p3 - cmd_cd part 3
 * @o_en: our global env
 * @path: path
 * ------------------------------------------
*/
void cd_p3(char ***o_en, char **path)
{
	char *aux_error = NULL, *aux = NULL;

	_setenv("LAST_CHILD_RET", "2", o_en);
	aux_error = _super_con_err("cd", o_en);
	aux = _strcon(aux_error, ": can't cd to ");
	free(aux_error);
	aux_error = _strcon(aux, *path);
	_print_2_n(aux_error);
	free(aux);
	free(aux_error);
	free(*path);
}


