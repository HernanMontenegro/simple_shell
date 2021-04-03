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


		/*printf("%s\n", command);*/

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
	envs_list *aux = NULL;

	list = generate_var_nodes(str, &tot_size);

	/*free(str);*/

	aux = list;
	for (; aux;)
	{
		printf("%s\n", aux->name);
		aux = aux->next;
	}


	free_list(list);
	return (str);
}
