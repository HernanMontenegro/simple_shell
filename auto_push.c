#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

void create_child(pid_t *);

int main(int ac, char **av)
{
	int status;
	int times;
	pid_t child_pid;
	char *git[] = {"/usr/bin/git", "add", ".", NULL};
	char *git_com[] = {"/usr/bin/git", "commit", "-m", av[1], NULL};
	char *git_push[] = {"/usr/bin/git", "push", NULL};
	char git_usr[] = "HernanMontenegro";

	for (times = 0; times < 4; times++)
	{
		create_child(&child_pid);
		/* Parent process case  */
		if (child_pid != 0)
			wait(&status);
                /* Child process case  */
		else
		{
			switch (times)
			{
				case 0: if (execve(git[0], git, NULL) == -1) perror("Error"); break;
				case 1: if (execve(git_com[0], git_com, NULL) == -1) perror("Error"); break;
				case 2: if (execve(git_push[0], git_push, NULL) == -1) perror("Error"); break;
				case 3: write(1, git_usr, sizeof(git_usr) / sizeof(char));
			}
		}
	}

	return (0);
}

void create_child(pid_t *child_pid)
{
	*child_pid = fork();
	/* Error case  */
	if (*child_pid == -1)
	{
		perror("Error:");
		exit (1);
	}
}
