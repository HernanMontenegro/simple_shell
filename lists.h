
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
void free_list(envs_list *head);
envs_list *add_node_end(envs_list **, char *, char *, int, int, int);
envs_list *generate_var_nodes(char *str, int *tot_size);
int check_var_delim(char c);

#endif /* LISTS_H */
