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
	int i;

	for (i = 0; input && input[i] != NULL; i++)
	{
		command = delete_comments(input[i]);
		if (!coomand)
			return (1);
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

	str_list = _split(str, '#');

	_strcpy(str_list[0], str_aux);

	free_split(str_list);

	return (str_aux);
}
