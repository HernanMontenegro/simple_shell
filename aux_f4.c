#include "our_header.h"

/**
 * calc_var_space - Calculate the space to insert var content
 * @head: the var linked list
 * @tot_size: previous space without the variable
 * -------------------------------------------------
 * Return: The total space requiered to insert the var content
*/
int calc_var_space(envs_list *head, int tot_size)
{
	int total = tot_size;
	envs_list *aux = head;

	for (; aux; aux = aux->next)
		total += aux->content_size;

	return (total);
}

/**
 * var_big_bang - Insert a var content in a string
 * @head: var linked list
 * @str: string given to modify
 * @tot_size: previous string size not taking var content into account
 * ----------------------------------------------------------
 * Return: A new string with the var content inserted
*/
char *var_big_bang(envs_list *head, char *str, int tot_size)
{
	int i, j, k;
	int total;
	char *universe;
	envs_list *aux = head;
	envs_list *pre_aux = NULL;

	total = calc_var_space(head, tot_size);

	universe = malloc((total + 1) * sizeof(char));
	if (!universe) /* Black hole */
		return (NULL);

	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		/* Repleace with the variable content */
		if (str[i] == '$')
		{
			pre_aux = aux;
			aux = aux->next;


			if (pre_aux->name == NULL && pre_aux->content == NULL)
			{
				universe[j] = '$';
				j++;
				continue;
			}

			for (k = 0; pre_aux->content && pre_aux->content[k] != '\0'; k++, j++)
				universe[j] = pre_aux->content[k];
			i = pre_aux->end_index;
		}
		else
		{
			universe[j] = str[i];
			j++;
		}
	}
	universe[j] = '\0';

	return (universe);
}

/**
 * copy_pstr - copy **char
 * @buff: **char
 * ----------------------------------------------------------
 * Return: **char
*/
char **copy_pstr(char **buff)
{
	int i = 0;
	int len_buff = p_strlen(buff);
	char **new_buff = NULL;

	new_buff = malloc((len_buff + 1) * sizeof(char *));
	if (!new_buff)
		return (NULL);

	for (i = 0; buff[i] != NULL; i++)
		new_buff[i] = _strcpy(buff[i]);
	new_buff[i] = NULL;

	return (new_buff);
}

/**
* p_realloc - re size array
* @buff: string
* @old_size: int
* @new_size: uns int
* ---------------------------------
* Return: void pointer
*/
char **p_realloc(char **buff, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, cal;
	char **p;
	char **new_buff;

	if (buff == NULL)
	{
		p = malloc(new_size * sizeof(char *));
		if (p == NULL)
			return (NULL);
		return (p);
	}
	else if (new_size == 0)
	{
		free(buff);
		return (NULL);
	}
	else if (new_size == old_size)
		return (buff);
	if (new_size > old_size)
		cal = old_size;
	else
		cal = new_size;
	p = malloc(new_size * sizeof(char *));
	if (p == NULL)
		return (NULL);
	new_buff = buff;
	for (i = 0; i < cal; i++)
		p[i] = new_buff[i];
	free(buff);
	return (p);
}

/**
 * 
*/ 
int _print(__attribute__((unused))char *s)
{
	

	return (0);
}