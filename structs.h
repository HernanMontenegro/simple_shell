
#ifndef STRUCTS_H
#define STRUCTS_H

/* ============================ */
/**
* struct in_com - internal commands
* @command: the command char pointer
* @f: the pointer to a function
* -----------------------------------------
* Description: Manages the internal commands
*/
typedef struct in_com
{
	char *command;
	void (*f)(int ac, char **av, char ***env, char ***alias, char ***o_en);

} internal_commands;

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

#endif /* STRUCTS_H */
