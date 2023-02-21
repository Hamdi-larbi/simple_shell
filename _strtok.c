#include "shell.h"

/**
 * _strtok - function that splits a string and returns
 * an array of each word of the string
 * @str: the string to be parsed
 * @delim: the delimeter
 * Return : an array of each word of the string
 */

char **_strtok(char *str, const char *delim)
{
	char **ptr, *temp;
	int i, j, m, n, k = 0, l = 0;

	temp = malloc(strlen(str) + 1);
	if (temp == NULL)
	{
		printf("ERROR: Memory allocation failed\n");
		exit(1);
	}
	ptr = malloc(strlen(str) * 2 * sizeof(char *));
	if (ptr == NULL)
	{
		printf("ERROR: Memory allocation failed\n");
		exit(1);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (str[i] == delim[j])
			{
				temp[l] = '\0';
				printf("temp %d : %s\n", k, temp);
				for (m = 0; temp[m] != '\0'; m++)
				{
					printf("debugging\n");
					ptr[k][m] = temp[m];
				}
				ptr[k++][m] = '\0';
				free(temp);
				temp = malloc((strlen(str) + 2 - l));
				if (temp == NULL)
				{
					printf("ERROR: Memory allocation failed\n");
					exit(1);
				}
				l = 0;
				break;
			}
		}
		if (delim[j] == '\0')
		{
			temp[l++] = str[i];
		}

	}
	temp[l] = '\0';
	for (n = 0; temp[n] != '\0'; n++)
	{
		ptr[k][n] = temp[n];
	}
	ptr[k++][n] = '\0';
	ptr[k] = NULL;
	free(temp);
	return (ptr);
}
