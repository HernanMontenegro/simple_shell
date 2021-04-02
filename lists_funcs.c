#include "lists.h"

/**
* list_len - calculates the length of a list
* @h: list element
* --------------------------
* Return: the length of the list
*/
size_t list_len(const list_t *h)
{
	size_t count = 0;
	list_t *search = (list_t *) h;

	if (!h)
		return (count);

	while (search)
	{
		search = (*search).next;
		count++;
	}

	return (count);
}

/**
* free_list - frees an entire list!!
* @head: where to start
* -----------------------------------
* Return: void
*/
void free_list(list_t *head)
{
	list_t *ram = head;

	for (; 1 == 1;)
	{
		ram = head;

		if (head == NULL)
			break;

		head = head->next;

		free(ram->str);
		free(ram);
	}
}
