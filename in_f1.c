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
 * cmd_exit - Exit internal command call advertiser
 * @ac: Argument count
 * @av: Arguments array
 * ----------------------------------------
 */
void cmd_env(__attribute__((unused)) int ac,__attribute__((unused)) char **av)
{
	int i;

	for (i = 0; global_env[i] != NULL; i++)
		printf("%s\n", global_env[i]);
}

void cmd_setenv(int ac, char **av)
{
	int i;
	int bool = 0;
	int global_env_len = 0;
	char **curr_env = NULL;
	char *aux1 = NULL;
	char *aux2 = NULL;

	if (ac >= 4)
	{
		printf("Too many arguments\n");
		last_child_ret = -1;
		return;
	}

	/* look if exist env var */
	for (i = 0; global_env[i] != NULL; i++)
	{
		curr_env = _split(global_env[i], "=");

		if (_strcmp(curr_env[0], av[1]) == 0)
		{
			free_split(curr_env);
			bool = 1;
			break;
		}

		free_split(curr_env);
	}
	aux1 = _strcon(av[1], "=");
	aux2 = _strcon(aux1, av[2]);
	free(aux1);

	if (bool)
	{
		free(global_env[i]);
		global_env[i] = aux2;
	}
	else
	{
		global_env_len = p_strlen(global_env);
		global_env = p_realloc(global_env, global_env_len, global_env_len + 2);

		global_env[global_env_len] = aux2;
		global_env[global_env_len + 1] = NULL;
	}

	last_child_ret = 0;
}

/**
 * cmd_exit - CD internal command call advertiser
 * @ac: Argument count
 * @av: Arguments array
 * ----------------------------------------
 */
void cmd_cd(int ac, char **av)
{
	int len_buff = 0;
	char *aux = NULL;
	char *path = NULL;
	char *path_old = NULL;
	char *av_env[] = {"setenv", "", "", NULL};

	if (ac == 1)
	{
		path = _getenv("HOME");
		path_old = _getenv("PWD");
	}
	else if (ac > 2)
	{
		printf("Too many arguments\n");
		last_child_ret = -1;
		return;
	}
	else if (ac == 2)
	{
		if (av[1][0] == '-')
		{
			path = _getenv("OLDPWD");
			path_old = _getenv("PWD");
		}
		else
		{
			path = _strcpy(av[1]);
			path_old = _getenv("PWD");
		}
	}

	if (chdir(path) == -1)
	{
		last_child_ret = 1;
		free(path);
		free(path_old);
		perror("Error");
		return;
	}
	aux = _getenv("PWD");
	len_buff = _strlen(path) + _strlen(aux) + 10;

	free(aux);
	free(path);

	path = _calloc(path, len_buff);
	path = getcwd(path, len_buff);

	av_env[1] = "OLDPWD";
	av_env[2] = path_old;
	cmd_setenv(3, av_env);

	av_env[1] = "PWD";
	av_env[2] = path;
	cmd_setenv(3, av_env);

	if (ac > 1 && av[1][0] == '-')
	{
		printf("%s\n", path);
	}

	free(path_old);
	free(path);
	last_child_ret = 0;
}
