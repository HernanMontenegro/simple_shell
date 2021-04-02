#include "our_header.h"

/**
*main - coso
*
Return: int
*/
int main(int ac, char **av)
{
	int fd = -1, ret = 0, read_site = 1;

	/* LEEMOS ARCHIVO */
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

	return (ret);
}


int infinite_loop(int fd, int read_site)
{
	char prompt[] = "#cisfun$ ";
	char *input = NULL;
	int bytes_used_read = 0;
	int bytes_read = 0;
	int ret = 0;
	char **lines = NULL;

	while (1)
	{
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

		lines = _split(input, '\n');
		free(input);

		ret = syntax_manager(lines);
		free_split(lines);
		if (ret == 1)
		{
			printf("Retorno syntax_manager\n\n");
			return (1);
		}

		if (fd != -1)
			break;
	}

	return (ret);
}
