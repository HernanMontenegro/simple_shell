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
	{
		return(WEXITSTATUS(*status));
	}

	return (1);
}

/**
* _magic - used
*@ac: none
*@av: none
*@env: none
*@alias: none
*/
void _magic(__attribute__((unused)) int ac, __attribute__((unused)) char **av,
__attribute__((unused)) char ***env, __attribute__((unused)) char ***alias)
{
}

/**
 * _setenv - Switch the value or create a new env var
 * @name: name of variable
 * @value: value of variable
 * @env: global env
 * ------------------------------------------
 */
void _setenv(char *name, char *value, char ***env)
{
	int global_env_len = 0, target_i = 0;
	char *target_env = NULL, *aux1 = NULL, *aux2 = NULL;

	/* look if exist env var */
	target_env = _getenv(name, *env);
	target_i = get_env_index(name, *env);

	aux1 = _strcon(name, "=");
	aux2 = _strcon(aux1, value);
	free(aux1);

	if (target_env)
	{
		free((*env)[target_i]);
		(*env)[target_i] = aux2;
	}
	else
	{
		global_env_len = p_strlen(*env);
		*env = p_realloc(*env, global_env_len, global_env_len + 2);

		(*env)[global_env_len] = aux2;
		(*env)[global_env_len + 1] = NULL;
	}
	free(target_env);
}

/**
*counter_plus_plus - variable counter++
*@env: global variables
*-------------------------------------------
*/
void counter_plus_plus(char ***env)
{
	int counter = 0;
	char *aux;

	aux = _getenv("COUNTER", *env);
	if (aux == NULL)
	{
		_setenv("COUNTER", "0", env);
		return;
	}
	counter = _atoi(aux);
	free(aux);
	counter++;
	aux = int_to_str(counter);
	_setenv("COUNTER", aux, env);
	free(aux);
}
