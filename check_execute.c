#include "shell.h"

/**
 * check_execute - check if command found 
 * in path and execute the program
 * @path_dir : array of string of commands
 * @input : array of arguments
 * Return: 0
 */

int check_execute(char **path_dir, char **input)
{
	int i;
	struct stat st;

	for (i =0; path_dir[i] != NULL; i++)
	{
		if (stat(path_dir[i], &st) == 0)
		{
			_execute(path_dir[i], input);
			break;
		}
	}
	return (0);
}
