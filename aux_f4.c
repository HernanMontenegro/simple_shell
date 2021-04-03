#include "our_header.c"

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
	int total = calc_var_space(head, tot_size);
	envs_list *aux = head;
	char *universe;
	char *content;

	universe = malloc((total + 1) * sizeof(char));
	if (!universe) /* Black hole */
		return (NULL);

	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		/* Repleace with the variable content */
		if (str[i] == '$')
		{
			content = aux->content;
			for (k = 0; content && content[k] != '\0'; k++, j++)
				universe[j] = content[k];
			i = aux->end_index;
		}
		else
		{
			universe[j] = str[i];
			j++;
		}
	}
	universe[i] = '\0';

	return (universe);
}