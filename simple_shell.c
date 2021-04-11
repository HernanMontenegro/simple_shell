#include "our_header.h"

int last_child_ret = 0;
char **global_env = NULL;
char **global_alias = NULL;

int abort_indicator = 0;
int abort_indicator_status = 0;

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

	signal(SIGINT, sighandler);

	/* Fill global var */
	global_env = copy_pstr(env);
	global_alias = create_start_alias();

	/* READ FILE */
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			perror("Error");
			return (1);
		}
		read_site = fd;
	}
	else if (!isatty(0))
	{
		fd = 0;
		read_site = 0;
	}

	ret = infinite_loop(fd, read_site);

	if (fd != -1)
		close(fd);

	free_split(global_env);
	free_split(global_alias);
	return (ret);
}

/**
 * infinite_loop - Execute until the program end asking user's input
 * @fd: pass main file descriptor
 * @read_site: where read?
 * ------------------------------
 * Return: syntax manager return, 1 if error happens
 */ 
int infinite_loop(int fd, int read_site)
{
	char prompt[] = "\033[0;32m#cisfun$ \033[1;37m";
	char *input = NULL;
	int bytes_used_read = 0;
	int bytes_read = 0;
	int ret = 0;
	char **lines = NULL;

	while (1)
	{
		if (abort_indicator)
		{
			free_split(global_env);
			free_split(global_alias);
		        exit(abort_indicator_status);
		}

		bytes_read = 0;
		bytes_used_read = 0;
		input = NULL;
		lines = NULL;

		/* Print prompt */
		if (fd == -1)
		write(1, &prompt, sizeof(prompt) / sizeof(char));

		bytes_read = _getline(&input, &bytes_used_read, read_site);
		if (bytes_read == -1)
		{
			free(input);
			return (1);
		}

		lines = _split(input, "\n");
		free(input);

		ret = syntax_manager(lines);
		free_split(lines);
		if (ret == 1)
		{
			_print("Retorno syntax_manager\n\n");
			return (1);
		}

		if (fd != -1)
			break;
	}

	return (ret);
}

/**
 * sighandler - writes the prompt with colors
 * @signum: get user keyboard input
 * ----------------------------------------
*/
void sighandler(__attribute__((unused)) int signum) {
	char prompt[] = "\n\033[0;32m#cisfun$ \033[1;37m";
	write(1, &prompt, sizeof(prompt) / sizeof(char));
}
