#include "shell.h"

/**
 * main - simple shell
 * Return: 0.
 */

int main(void)
{
	extern char **environ;
	char *lineptr;
	size_t size = 32;
	int i, status;
	pid_t pid;
	char *args[2];

	while (1)
	{
		printf("shell> ");
		lineptr = malloc(size * sizeof(char));
		if (lineptr == NULL)
		{
			perror("unable to allocate lineptr");
			exit(1);
		}
		i = _getline(&lineptr, &size, stdin);
		if (i == -1)
			break;
		lineptr[i - 1] = '\0';
		if (strlen(lineptr) == 0)
			continue;
		else
		{
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				args[0] = lineptr;
				args[1] = NULL;
				if (execve(args[0], args, environ) == -1)
				{
					perror("./hsh ");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				if (wait(&status) == -1)
				{
					perror("wait");
					exit(EXIT_FAILURE);
				}
			}
			if (strcmp(lineptr, "exit") == 0)
				break;
			free(lineptr);
		}
	}
	return (0);
}
