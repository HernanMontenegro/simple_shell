#include "our_header.h"

/**
* syntax_manager - manages the syntax in our shell
* @input: the input str
* -------------------------------
* Return: 0 if worked, 1 if not
*/
int syntax_manager(char **input)
{
	char *command = NULL;
	int i, j;
	char **cmd_splt = NULL; /* Slpit by ; */

	for (i = 0; input && input[i] != NULL; i++)
	{
		if (input[i][0] == '\0')
			continue;

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
		command = variable_translator(command);
		if (!command)
			return (1);


		cmd_splt = _split(command, ";");

		for (j = 0; cmd_splt[j] != NULL; j++)
		{
			printf("%s\n", cmd_splt[j]);
			

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
*/
char *variable_translator(char *str)
{
	int tot_size = 0;
	envs_list *list = NULL;
	char *new_str = NULL;

	list = generate_var_nodes(str, &tot_size);
	gen_var_content(list);
	new_str = var_big_bang(list, str, tot_size);
	free(str);

	free_list(list);
	return (new_str);
}
