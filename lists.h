
#ifndef LISTS_H
#define LISTS_H

/* ============================ */
/**
* struct envs_list - singly linked list
* @name: the variable name
* @content: the variable content
* @name_size: size of the variable name
* @content_size: the size of the variable content
* @end_index: the original string index after the variable found
* @next: points to the next node
* -------------------------------------------------------
* Description: singly linked list node structure
* for Holberton project
*/
typedef struct envs_list
{
	char *name;
	char *content;
	int name_size;
	int content_size;
	int end_index;
	struct envs_list *next;
} envs_list;
/* ============================ */

/* Prototypes */
size_t list_len(const list_t *h);
void free_list(list_t *head);
envs_list *add_node(envs_list, const char *);
envs_list *add_node_end(envs_list **, const char *);

#endif /* LISTS_H */
