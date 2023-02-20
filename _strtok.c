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
	int i, j, k = 0, l = 0;

	temp = malloc(strlen(str) + 1);
	if (temp == NULL)
	{
		printf("ERROR: Memory allocation failed\n");
		exit(1);
	}
	ptr = malloc(strlen(str) * 2);
	if (ptr == NULL)
	{
		printf("ERROR: Memory allocation failed\n");
		exit(1);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		printf("boucle i : %d\n", i);
		for (j = 0; delim[j] != '\0'; j++)
		{
			printf("boucle j : %d\n", j);
			if (str[i] == delim[j])
			{
				temp[l] = '\0';
				printf("print temp de %d : %s\n", l, temp);
				ptr[k++] = temp;
				free(temp);
				printf("print ptr de %d : %s\n", k - 1 , ptr[k - 1]);
				temp = malloc((strlen(str) + 2 - l));
				if (temp == NULL)
				{
					printf("ERROR: Memory allocation failed\n");
					exit(1);
				}
//				printf("j est egal a : %d\n", j);
				l = 0;
				break;
			}
		}
		if (delim[j] == '\0')
		{
//			printf("la boucle j est fini : %d\n", j);
			temp[l++] = str[i];
		}

	}
	temp[l] = '\0';
	printf("print temp de %d : %s\n", l, temp);
	ptr[k++] = temp;
	printf("print ptr de %d : %s\n", k - 1, ptr[k - 1]);
	ptr[k] = NULL;
	free(temp);
	printf("c'est la fin de la fonction strtok");
	return (ptr);
}
