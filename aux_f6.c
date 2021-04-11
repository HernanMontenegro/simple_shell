#include "our_header.h"

/**
 * str_char_check - check if an string has a char
 * @str: the string to check
 * @c: the char to look
 * -----------------------------------------------
 * Return: 1 if the char was found, 0 if not
*/
int str_char_check(char *str, char c)
{
	int i;
	int status = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
		{
			status = 1;
			break;
		}
	}

	return (status);
}

/**
 * parent_wait - manage the wait of the parent process
 * @child_pid: the child proccess file descriptor id
 * @status: pointer to status variable
 * ------------------------------------------
 *Return: 1 if everything was right, 0 if not
*/
int parent_wait(int child_pid, int *status)
{
	if (waitpid(child_pid, status, 0) == -1)
	{
		perror("Waitpid failed");
		return (0);
	}
	if (WIFEXITED(*status))
		last_child_ret = WEXITSTATUS(*status);

	return (1);
}
