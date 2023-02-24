#include "shell.h"

/**
 * main - simple shell
 * Return: 0.
 */

int main(void)
{
	char *lineptr, **env = __environ;
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
			free(lineptr);
			printf("\n");
			exit(0);
		//	break;
		}
		lineptr[i - 1] = '\0';
		if (strlen(lineptr) == 0)
		{
			free(lineptr);
			continue;
		}
		else
		{
		/*check build-in*/
			if (strcmp(lineptr, "exit") == 0)
			{
				free(lineptr);
				exit(0);
			}
			else if (strcmp(lineptr, "env") == 0)
			{
				while (*env)
				{
					printf("%s\n", *env);
					env++;
				}
				free(lineptr);
			}
			else
			{
				check_execute(lineptr);
				free(lineptr);
			}
		}
	}
	return (0);
}
