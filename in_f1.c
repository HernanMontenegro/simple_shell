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

		if (_strcmp(curr_env[0], av[1]))
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
		global_env = _realloc(global_env, global_env_len, global_env_len + 1);

		global_env[global_env_len] = aux2;
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
	cmd_setenv(ac, av);
}
