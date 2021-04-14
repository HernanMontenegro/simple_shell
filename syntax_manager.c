#include "our_header.h"

/**
* syntax_manager - manages the syntax in our shell
* @input: the input str
* @fd: file descriptor
* @env: global env variables
* @alias: global alias variable
* -------------------------------
* Return: 0 if worked, 1 if not
*/
int syntax_manager(char **input, int fd, char ***env, char ***alias)
{
	int i, j;
	char **cmd_splt = NULL, *command = NULL; /* Slpit by ; */

	if (input[0][0] == '\0')
		counter_plus_plus(env);

	for (i = 0; input && input[i] != NULL; i++)
	{
		if (fd != -1)
			counter_plus_plus(env);
		if (input[i][0] == '\0')
			continue;
		if (fd == -1)
			counter_plus_plus(env);
		command = delete_comments(input[i]);
		if (!command)
			return (1);
		/* Si esta vacio entonces continue; */
		if (_strlen(command) == 0)
		{
			free(command);
			continue;
		}
		/* Traslate variables */
		command = variable_translator(command, env);
		if (!command)
			return (1);
		cmd_splt = _split(command, ";");
		for (j = 0; cmd_splt[j] != NULL; j++)
		{
			or_operat(cmd_splt[j], env, alias);
		
			if (get_int_env("ABORT_INDICATOR", env))
			{
				free_split(cmd_splt);
				free(command);
				return (0);
			}
		}
		free_split(cmd_splt);
		free(command);
	}
	return (0);
}

/**
* delete_comments - delete comments xd
* @str: the string to check
* -----------------------------
* Return: the uncommented string
*/
char *delete_comments(char *str)
{
	char **str_list = NULL;
	char *str_aux = NULL;

	str_list = _split(str, "#");

	str_aux = _strcpy(str_list[0]);

	free_split(str_list);
	return (str_aux);
}

/**
 * variable_translator - Translate a variable with it's content.
 *						More like a brain calling functions requiered
 * @str: the source string containing a variable
 * @env: global env variables
 * ------------------------------------------------
 * Return: New string with var content
*/
char *variable_translator(char *str, char ***env)
{
	int tot_size = 0;
	envs_list *list = NULL;
	char *new_str = NULL;

	list = generate_var_nodes(str, &tot_size, env);
	gen_var_content(list, env);
	new_str = var_big_bang(list, str, tot_size);
	free(str);

	free_list(list);
	return (new_str);
}

/**
 * or_operat - Manages the "||" - OR operator
 * @str: the string containing the OR operator
 * @env: global env variables
 * @alias: global alias variable
 * ----------------------------------------------
 * Return: 0 FOR NOW
 */
int or_operat(char *str, char ***env, char ***alias)
{
	int i, ret_and;
	char **cmd_splt_or = NULL;

	cmd_splt_or = _split(str, "||");

	for (i = 0; cmd_splt_or[i] != NULL; i++)
	{
		ret_and = and_operat(cmd_splt_or[i], env, alias);
		if (get_int_env("ABORT_INDICATOR", env))
		{
			free_split(cmd_splt_or);
			return (1);
		}
		if (ret_and == 1)
			break;
	}

	free_split(cmd_splt_or);
	return (0);
}

/**
 * and_operat - Manages the "&&" - AND operator
 * @str: the string containing the AND operator
 * @env: global env variables
 * @alias: global alias variable
 * ----------------------------------------------
 * Return: 1 FOR NOW
 */
int and_operat(char *str, char ***env, char ***alias)
{
	int i, ret;
	char **cmd_splt_and = NULL;

	cmd_splt_and = _split(str, "&&");

	for (i = 0; cmd_splt_and[i] != NULL; i++)
	{
		ret = localize_cmd(cmd_splt_and[i], env, alias);
		if (get_int_env("ABORT_INDICATOR", env))
		{
			free_split(cmd_splt_and);
			return (1);
		}
		if (ret != 0)
		{
			free_split(cmd_splt_and);
			return (0);
		}
	}

	free_split(cmd_splt_and);
	return (1);
}
