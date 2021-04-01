#include "our_header.h"

int syntax_manager(char **input)
{
	char *command = NULL;
	int i;

	for (i = 0; input && input[i] != NULL; i++)
	{
		command = delete_comments(input[i]);
		printf("command: %s\n", command);
		free(command);
	}

	return (0);
}

char *delete_comments(char *str)
{
	char **str_list = NULL;
	char *str_aux = NULL;

	str_list = _split(str, '#');

	_strcpy(str_list[0], str_aux);

	free_split(str_list);

	return (str_aux);
}
