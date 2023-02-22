#include "shell.h"

/**
 * main - simple shell
 * Return: 0.
 */

int main(void)
{
	char *lineptr;
	char **input;
	size_t size = 32;
	int i;

	while (1)
	{
		printf("#cisfun$ ");
		lineptr = malloc(size * sizeof(char));
		if (lineptr == NULL)
		{
			perror("unable to allocate lineptr");
			exit(1);
		}
		i = _getline(&lineptr, &size, stdin);
		if (i == -1)
		{
			printf("\n");
			break;
		}
		lineptr[i - 1] = '\0';
		if (strlen(lineptr) == 0)
			continue;
		else
		{
			input = _strtok(lineptr, " ");
			check_execute(_command_path(input), input);
			if (strcmp(lineptr, "exit") == 0)
				break;
			free(lineptr);
		}
	}
	return (0);
}
