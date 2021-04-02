#include "lists.h"

/**
* list_len - calculates the length of a list
* @h: list element
* --------------------------
* Return: the length of the list
*/
size_t list_len(const envs_list *h)
{
	size_t count = 0;
	envs_list *search = (envs_list *) h;

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
void free_list(envs_list *head)
{
	envs_list *ram = head;

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

/**
* add_node - adds a new node
* @head: the head pointer reference
* @str: string given
* -------------------------------------
* Return: a new node
*/
envs_list *add_node(envs_list **head, const char *str)
{
        envs_list *new_obj;

        new_obj = malloc(sizeof(envs_list));
        if (!new_obj)
                return (NULL);
        new_obj->str = strdup(str);
        new_obj->len = _strlen(str);
        new_obj->next = *head;

        (*head) = new_obj;

        return (new_obj);
}

/**
* add_node_end - adds a node at the end
* @head: head reference
* @str: string to add
* -------------------------------------
* Return: a new node
*/
envs_list *add_node_end(envs_list **head, const char *str)
{
        envs_list *new_obj = NULL, *previous = NULL;

        new_obj = malloc(sizeof(envs_list));
        if (!new_obj)
                return (NULL);
        new_obj->str = strdup(str);
        new_obj->len = _strlen(str);
        new_obj->next = NULL;

        if (!*head)
        {
                *head = new_obj;
                return (new_obj);
        }

        previous = *head;

        while ((*previous).next)
                previous = (*previous).next;
        previous->next = new_obj;

        return (new_obj);
}
