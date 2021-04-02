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

		printf("%s\n", command);

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

	generate_var_nodes(str, &tot_size);
}

envs_list *generate_var_nodes(char *str, int *tot_size)
{
	char *aux = NULL
	envs_list *head = NULL;
	int i, cnt, j;

        for (i = 0; str[i] != '\0'; i++)
        {
                if (str[i] != '$')
		{
			*tot_size = *tot_size + 1;
                        continue;
                }
		/* i = '$' || i = '?' */
                i++;
                if (str[i] == '$')
                {
			aux = int_to_str(getpid());
			add_node_end(&head, "$", aux, 1, _strlen(aux), i);
			continue;
                }
		else if (str[i] == '?')
		{
			aux = int_to_str(last_child_ret);
			add_node_end(&head, "?", aux, 1, _strlen(aux), i);
			continue;
		}

		for (cnt = 0; check_var_delim(str[i + cnt]); cnt++)
			; /* O.o  Cursed */

		aux = malloc((cnt + 1) * sizeof(char))
		if (!aux)
		{
			free_list(head);
			return (NULL);
        	}

		for (j = 0; check_var_delim(str[i]); i++, j++)
			aux[j] = str[i];
		aux[j] = '\0';

		add_node_end(&head, aux, cnt, -1, NULL, i);
	}

	return (head);
}

int check_var_delim(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else if (c >= 97 && c <= 122)
		return (1);
	else if (c >= 65 && c <= 90)
		return (1);
	else if (c == 95)
		return (1);
	return (0);
}
