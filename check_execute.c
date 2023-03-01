#include "shell.h"

/**
 * check_execute - check if command found
 * in path and execute the program
 * @lineptr : string of commands from the std input
 * Return: shell status
 */

int check_execute(char *lineptr)
{
	int i, j;
	int k, shell_status = 0;
	struct stat st = {0};
	char **path_dir, **input, **input_zero;

	input = _strtok(lineptr, " ");
	if (input[0] == NULL)
	{
		free(input);
		return (-1);
	}
	path_dir = _command_path(input);
	input_zero = _strtok(input[0], "/");
	for (j = 0; input_zero[j]; j++)
		;
	if (j <= 1)
	{
		for (i = 0; path_dir[i] != NULL; i++)
		{
			if (stat(path_dir[i], &st) == 0)
			{
				_execute(path_dir[i], input);
				break;
			}
		}
	}
	else
	{
		if (stat(input[0], &st) == 0)
			shell_status = _execute(input[0], input);
	}
	for (k = 0; path_dir[k]; k++)
	{
		free(path_dir[k]);
		path_dir[k] = NULL;
	}
	free(path_dir);
	path_dir = NULL;
	for (k = 0; input[k]; k++)
	{
		free(input[k]);
		input[k] = NULL;
	}
	free(input);
	input = NULL;
	for (k = 0; input_zero[k]; k++)
	{
		free(input_zero[k]);
		input_zero[k] = NULL;
	}
	free(input_zero);
	input_zero = NULL;
	return (shell_status);
}
