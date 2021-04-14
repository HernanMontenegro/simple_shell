#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <limits.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	pid_t my_pid;
	pid_t child_pid;
	int status = 0;
	char *baby_av[] = {"./hsh", NULL};
	char **env_h = NULL;


	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}

	my_pid = getpid();
	if (child_pid == 0)
	{
		if (execve(baby_av[0], baby_av, env) == -1)
		{
			printf("Fallo fork\n");
			exit (126);
		}

	}
	else
	{
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("Waitpid failed");
			return (0);
		}
		if (WIFEXITED(status))
		{
			printf("Status Hijo");
			return(WEXITSTATUS(status));
		}
		printf("Termino");
	}
	return (0);
}
