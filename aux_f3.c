#include "our_header.h"

/**
* free_list - frees an entire list!!
* @head: where to start
* -----------------------------------
* Return: void
*/
void free_list(envs_list *head)
{
	envs_list *ram = head;

	for (; 1 == 1;)
	{
		ram = head;

		if (head == NULL)
			break;

		head = head->next;

		if (ram->name != NULL)
			free(ram->name);

		if (ram->content != NULL)
			free(ram->content);
		free(ram);
	}
}

/**
* add_node_end - adds a node at the end
* @h: head reference
* @n: var name
* @c: var content
* @ne: name size
* @ce: content size
* @ed: final index
* -------------------------------------
* Return: a new node in the list
*/
envs_list *add_node_end(envs_list **h, char *n, char *c, int ne, int ce, int ed)
{
	envs_list *new_obj = NULL, *previous = NULL;

	new_obj = malloc(sizeof(envs_list));
	if (!new_obj)
		return (NULL);
	new_obj->name = n;
	new_obj->content = c;
	new_obj->name_size = ne;
	new_obj->content_size = ce;
	new_obj->end_index = ed;
	new_obj->next = NULL;

	if (!*h)
	{
		*h = new_obj;
		return (new_obj);
	}
	previous = *h;

	while ((*previous).next)
		previous = (*previous).next;
	previous->next = new_obj;

	return (new_obj);
}

/**
 * generate_var_nodes - create a new node in our var list with it's info
 * @str: the string to search for a variable
 * @tot_size: pointer to an int that counts until a variable has been found
 * -----------------------------------------------------
 * Return: an entire linked list with a new node
 */
envs_list *generate_var_nodes(char *str, int *tot_size)
{
	char *aux = NULL;
	envs_list *head = NULL;
	int i, cnt, j;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '$')
		{
			*tot_size = *tot_size + 1;
			continue;
		}
		i++;
		if (str[i] == '$' || str[i] == '?')
		{
			if (str[i] == '$')
				aux = int_to_str(getpid());
			else
				aux = int_to_str(last_child_ret);
			add_node_end(&head, NULL, aux, 1, _strlen(aux), i);
			continue;
		}
		for (cnt = 0; check_var_delim(str[i + cnt]); cnt++)
			; /* O.o  Cursed */
		if (cnt == 0 || str[i] == '\0')
		{
			add_node_end(&head, NULL, NULL, 0, 1, i--);
			continue;
		}
		aux = malloc((cnt + 1) * sizeof(char));
		if (!aux)
		{
			free_list(head);
			return (NULL);
		}
		for (j = 0; check_var_delim(str[i]); i++, j++)
			aux[j] = str[i];
		aux[j] = '\0';
		add_node_end(&head, aux, NULL, cnt, 0, --i);
	}
	return (head);
}

/**
 * check_var_delim - Check if the given char is valid for a var
 * @c: the given char
 * --------------------------------------
 * Return: 1 if is a valid char, 0 if not
*/
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

/**
 * gen_var_content - Create the variable content
 * @head: the var linked list to generate content
 * ------------------------------------------------
*/
void gen_var_content(envs_list *head)
{
	envs_list *aux = head;
	char *aux_env = NULL;

	while (aux != NULL)
	{
		if (!aux->name)
		{
			aux = aux->next;
			continue;
		}

		aux_env = _getenv(aux->name);
		if (!aux_env)
		{
			aux = aux->next;
			continue;
		}

		aux->content = _strcpy(aux_env);
		aux->content_size = _strlen(aux_env);
		free(aux_env);

		aux = aux->next;
	}
}

