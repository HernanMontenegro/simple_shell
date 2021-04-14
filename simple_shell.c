#include "our_header.h"

void sighandler(int signum);

/**
 * main - entry point
 * @ac: argument count
 * @av: arguments array
 * @env: father environmental variables
 * -----------------------------------------
 * Return: 0 if worked, 1 if not
*/
int main(int ac, char **av, char **env)
{
	int fd = -1, ret = 0, read_site = 1;
	char **global_env = NULL;
	char **our_env = NULL;
	char **global_alias = NULL;
	char *aux_error = NULL, *aux = NULL;

	signal(SIGINT, sighandler);

	/* Fill global var */
	global_env = copy_pstr(env);
	global_alias = create_start_alias();

	_set_PWD(&global_env);
	
	our_env = malloc(sizeof(char *) * 1);
	our_env[0] = NULL;

	_setenv("LAST_CHILD_RET", "0", &our_env);
	_setenv("ABORT_INDICATOR", "0", &our_env);
	_setenv("ABORT_INDICATOR_STATUS", "0", &our_env);
	_setenv("COUNTER", "0", &our_env);
	_setenv("PROG_NAME", av[0], &our_env);
	
	
	/* READ FILE */
	if (ac >= 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			aux_error = _super_con_err("Can't open ", &our_env);
			aux = _strcon(aux_error, av[1]);
			_print_2_n(aux);
			_setenv("LAST_CHILD_RET", "127", &our_env);
			free(aux);
			free(aux_error);
			return (127);
		}
		read_site = fd;
	}
	else if (!isatty(0))
	{
		fd = 0;
		read_site = 0;
	}

	_setenv("COUNTER", "1", &our_env);
	ret = infinite_loop(fd, read_site, &global_env, &global_alias, &our_env);

	if (fd != -1)
		close(fd);

	free_split(global_env);
	free_split(global_alias);
	free_split(our_env);
	return (ret);
}

/**
 * infinite_loop - Execute until the program end asking user's input
 * @fd: pass main file descriptor
 * @rs: where read?
 * @env: global env variables
 * @alias: global alias variable
 * @o_en: our global variables
 * ------------------------------
 * Return: syntax manager return, 1 if error happens
 */
int infinite_loop(int fd, int rs, char ***env, char ***alias, char ***o_en)
{
	char prompt[] = "\033[0;32m#cisfun$ \033[1;37m";
	char *input = NULL, **lines = NULL;
	int bytes_used_read = 0;
	int bytes_read = 0, ret = 0, abort_indicator_status = 0;

	while (1)
	{
		bytes_read = 0;
		bytes_used_read = 0;
		input = NULL;
		lines = NULL;
		if (fd == -1)
			write(1, &prompt, sizeof(prompt) / sizeof(char));
		bytes_read = _getline(&input, &bytes_used_read, rs);
		if (bytes_read == -1)
		{
			free(input);
			return (1);
		}
		lines = _split(input, "\n");
		free(input);
		ret = syntax_manager(lines, fd, env, alias, o_en);
		free_split(lines);
		if (ret == 1)
		{
			_print("Retorno syntax_manager\n\n");
			return (1);
		}
		if (get_int_env("ABORT_INDICATOR", o_en) == 1)
		{
			abort_indicator_status = get_int_env("ABORT_INDICATOR_STATUS", o_en);
			free_split(*env);
			free_split(*alias);
			free_split(*o_en);
			exit(abort_indicator_status);
		}
		if (fd != -1)
			break;
	}
	return (get_int_env("LAST_CHILD_RET", o_en));
}

/**
 * sighandler - writes the prompt with colors
 * @signum: get user keyboard input
 * ----------------------------------------
*/
void sighandler(__attribute__((unused)) int signum)
{
	char prompt[] = "\n\033[0;32m#cisfun$ \033[1;37m";

	write(1, &prompt, sizeof(prompt) / sizeof(char));
}
