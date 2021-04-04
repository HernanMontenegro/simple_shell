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