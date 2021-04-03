#include "our_header.h"

/**
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
*/
char *var_big_bang(envs_list *head, char *str, int tot_size)
{
	int i, j, k;
	int total;
	envs_list *aux = head;
	char *universe;
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