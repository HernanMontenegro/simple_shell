#include "our_header.h"

/**
* _super_con_err - variable counter++
* @baby_av: argument
* @env: global variables
* -------------------------------------------
* Return: SUPER STRING
*/
char *_super_con_err(char *baby_av, char ***env)
{
	char *aux = NULL;
	char *con1 = NULL;
	char *con2 = NULL;

	aux = _getenv("prog_name", *env);
	con1 = _strcon(aux, ": ");
	free(aux);

	aux = _getenv("counter", *env);
	con2 = _strcon(con1, aux);
	free(con1);
	free(aux);

	con1 = _strcon(con2, ": ");
	free(con2);

	con2 = _strcon(con1, baby_av);
	free(con1);

	return (con2);
}

/**
 * get_int_env - get an int value from an env
 * @name: name string of the env variable
 * @env: global env variables
 * ---------------------------------------------
 * Return: the int value of an env
*/
int get_int_env(char *name, char ***env)
{
	char *aux = NULL;
	int num = 0;

	aux = _getenv(name, *env);
	num = _atoi(aux);
	free(aux);

	return (num);
}

/**
*
*/
int check_dir(char *dir_path)
{
	DIR *dir = NULL;

	dir = opendir(dir_path);
	if (dir)
	{
		closedir(dir);
		return (1);
	}

	return (0);
}
