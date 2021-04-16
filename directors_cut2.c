#include "our_header.h"

/**
 * sytx_man_p2 - syntax manager part 2 xd
 * @fd: file descriptor
 * @o_en: our global env var
 * @cmd_split: cdm_split
 * @cmmd: command
 * -------------------------------------
*/
void sytx_man_p2(int fd, char ***o_en, char ***cmd_split, char **cmmd)
{
	if (fd == -1)
		counter_plus_plus(o_en);
	free_split(*cmd_split);
	free(*cmmd);
}

/**
 * sytx_man_p3 - syntax manager part 3 xd
 * @fd: file descriptor
 * @o_en: our global env var
 * -----------------------------------------
*/
void sytx_man_p3(int fd, char ***o_en)
{
	if (fd != -1)
		counter_plus_plus(o_en);
}

int extrn_cmd_2(char **baby_av, int *bool, struct stat *st,
char **aux, char **aux2, char ***o_en, char ***env)
{
	if (!(str_char_check(baby_av[0], '/')))
		*bool = 1;
	else
		if (stat(*baby_av, st) == 0)
			*bool = 0;
		else
			*bool = 1;
	if (*bool)
	{
		*aux = serch_path(*baby_av, env);
		if (!*aux)
		{
			*aux2 = int_to_str(127);
			_setenv("LAST_CHILD_RET", *aux2, o_en);
			free(*aux2);
			return (0);
		}
	}
	else
		*aux = _strcpy(*baby_av);

	return (1);
}

/**
 * extrn_cmd_3 - external_cmd part 3
 * @aux: aux
 * @o_en: our global env vars
 * --------------------------------
*/
void extrn_cmd_3(char **aux, char ***o_en)
{
	char *aux_error = NULL;

	aux_error = _super_con_err(*aux, o_en);
	perror(aux_error);
	free(aux_error);
	exit(126);
}
