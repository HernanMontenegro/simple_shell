#include "our_header.h"

/**
* syntax_manager - manages the syntax in our shell
* @inp: the input str
* @fd: file descriptor
* @env: global env variables
* @alis: global alias variable
* @o_en: our global variable
* -------------------------------
* Return: 0 if worked, 1 if not
*/
int syntax_manager(char **inp, int fd, char ***env, char ***alis, char ***o_en)
{
	int i, j;
	char **cmd_splt = NULL, *command = NULL;

	if (inp[0][0] == '\0')
		counter_plus_plus(o_en);

	for (i = 0; inp && inp[i] != NULL; i++)
	{
		if (inp[i][0] != '\0')
		{
			command = delete_comments(inp[i]);
			if (!command)
				return (1);
			if (_strlen(command) == 0)
			{
				counter_plus_plus(o_en);
				free(command);
				continue;
			}
			command = variable_translator(command, env, o_en);
			if (!command)
			{
				counter_plus_plus(o_en);
				return (1);
			}

			cmd_splt = _split(command, ";");
			for (j = 0; cmd_splt[j] != NULL; j++)
			{
				or_operat(cmd_splt[j], env, alis, o_en);

				if (get_int_env("ABORT_INDICATOR", o_en))
				{
					free_split(cmd_splt);
					free(command);
					return (0);
				}
			}

			if (fd == -1)
				counter_plus_plus(o_en);
			free_split(cmd_splt);
			free(command);
		}
		if (fd != -1)
			counter_plus_plus(o_en);
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

	if (str[0] == '#')
		return (_strcpy(""));

	str_list = _split(str, " #");

	str_aux = _strcpy(str_list[0]);

	free_split(str_list);
	return (str_aux);
}

/**
 * variable_translator - Translate a variable with it's content.
 *						More like a brain calling functions requiered
 * @str: the source string containing a variable
 * @env: global env variables
 * @o_en: our global variable
 * ------------------------------------------------
 * Return: New string with var content
*/
char *variable_translator(char *str, char ***env, char ***o_en)
{
	int tot_size = 0;
	envs_list *list = NULL;
	char *new_str = NULL;

	list = generate_var_nodes(str, &tot_size, o_en);
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
 * @o_en: our global variable
 * ----------------------------------------------
 * Return: 0 FOR NOW
 */
int or_operat(char *str, char ***env, char ***alias, char ***o_en)
{
	int i, ret_and;
	char **cmd_splt_or = NULL;

	cmd_splt_or = _split(str, "||");

	for (i = 0; cmd_splt_or[i] != NULL; i++)
	{
		ret_and = and_operat(cmd_splt_or[i], env, alias, o_en);
		if (get_int_env("ABORT_INDICATOR", o_en))
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
 * @o_en: our global variable
 * ----------------------------------------------
 * Return: 1 FOR NOW
 */
int and_operat(char *str, char ***env, char ***alias, char ***o_en)
{
	int i, ret;
	char **cmd_splt_and = NULL;

	cmd_splt_and = _split(str, "&&");

	for (i = 0; cmd_splt_and[i] != NULL; i++)
	{
		ret = localize_cmd(cmd_splt_and[i], env, alias, o_en);
		if (get_int_env("ABORT_INDICATOR", o_en))
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
