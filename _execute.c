#include "shell.h"

/**
 * _execute - execute the command line
 * @args : the string of arguments to be executed
 * @command_path : the command to be executed
 * Return: the shell status
 */

int _execute(char *command_path, char **args)
{
	pid_t pid;
	int status, shell_status = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(command_path, args, environ) == -1)
		{
			perror("./hsh ");
			exit(1);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			exit(1);
		}
	}
	if (WIFEXITED(status))
	{
		shell_status = WEXITSTATUS(status);
	}
	return (shell_status);
}
