#include "shell.h"

/**
 * _execute - execute the command line
 * @input : the string of command to be executed
 * Return: 0
 */

int _execute(char *input)
{
	pid_t pid;
	char *args[2];
	extern char **environ;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		args[0] = input;
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
	return (0);
}
