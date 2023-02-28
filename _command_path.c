#include "shell.h"

/**
 * _command_path - return the command path
 * @input : the commande to be searchen
 * Return: array of strings
 */


char **_command_path(char **input)
{
	char *path;
	char **directories;
	char **command_path;
	int size_cpath = 8;
	int i, j, k;

	path = getenv("PATH");
	directories = _strtok(path, ":");
	command_path = malloc(size_cpath * sizeof(*command_path));
	if (command_path == NULL)
	{
		printf("ERROR: Memory allocation failed\n");
		exit(1);
	}
	for (i = 0; directories[i]; i++)
	{
		if (i >= size_cpath)
		{
			size_cpath *= 2;
			command_path = realloc(command_path, size_cpath * sizeof(*command_path));
			if (command_path == NULL)
			{
				printf("ERROR: Memory allocation failed\n");
				exit(1);
			}
		}
		command_path[i] = malloc((strlen(directories[i]) + strlen(input[0]) + 2) * sizeof(char));
		if (command_path[i] == NULL)
		{
			printf("ERROR: Memory allocation failed\n");
			exit(1);
		}
		for (j = 0; directories[i][j] != '\0'; j++)
			command_path[i][j] = directories[i][j];
		command_path[i][j] = '/';
		for (k = 0; input[0][k] != '\0'; k++)
			command_path[i][j + 1 + k] = input[0][k];
		command_path[i][j + 1 + k] = '\0';
	}
	command_path[i] = NULL;
	for (i = 0; directories[i]; i++)
	{
		free(directories[i]);
		directories[i] = NULL;
	}
	free(directories);
	directories = NULL;
	return (command_path);
}
