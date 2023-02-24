#include "shell.h"

/**
 * check_execute - check if command found 
 * in path and execute the program
 * @lineptr : string of commands from the std input
 * Return: 0
 */

int check_execute(char *lineptr)
{
	int i, j;
	struct stat st;
	char **path_dir, **input, **input_zero;

	input = _strtok(lineptr, " ");
	path_dir = _command_path(input);
	input_zero = _strtok(input[0], "/");
	for (j = 0; input_zero[j]; j++)
		;
	if (j <= 1)
	{
		for (i =0; path_dir[i] != NULL; i++)
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
                        _execute(input[0], input);
	}
	free(path_dir);
	free(input);
	free(input_zero);
	return (0);
}
