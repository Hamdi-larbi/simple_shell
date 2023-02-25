#include "shell.h"

/**
 * _strtok - function that splits a string and returns
 * an array of each word of the string
 * @str: the string to be parsed
 * @delim: the delimeter
 * Return: an array of each word of the string
 */

char **_strtok(char *str, const char *delim)
{
	char **ptr, *temp;
	int i, j, m, n, k = 0, l = 0;
	int ptr_size = 2;

	temp = malloc(strlen(str) + 1);
	/*allocate memory for the temporary string*/
	if (temp == NULL)
	{
		printf("ERROR: Memory allocation failed\n");
		exit(1);
	}
	ptr = malloc(ptr_size * sizeof(char *));
	/*allocate memory for the array of strings*/
	if (ptr == NULL)
	{
		printf("ERROR: Memory allocation failed\n");
		exit(1);
	}
	for (i = 0; str[i] != '\0'; i++)
		/*loop on the string to be plited*/
	{
		for (j = 0; delim[j] != '\0'; j++)
			/*loop on the delimiter*/
		{
			if (str[i] == delim[j])
				/*test if there is a much withe the delimiter*/
			{
				temp[l] = '\0';
				/*termiate the temporary string with the null caracter*/
				if (temp[0] != '\0')
				{
					ptr[k] = malloc((l + 1) * sizeof(char));
				/*allocate the memory for the k th string*/
					if (ptr[k] == NULL)
					{
						printf("ERROR: Memory allocation failed\n");
						exit(1);
					}
					for (m = 0; temp[m] != '\0'; m++)
					/*copy the string from the temporary to the k th ptr array*/
					{
						ptr[k][m] = temp[m];
					}
					ptr[k++][m] = '\0';
					if (k >= ptr_size)
					/*test if the memory allocated to ptr still fit*/
					{
						ptr_size *= 2;
						ptr = realloc(ptr, ptr_size * sizeof(char *));
						if (ptr == NULL)
						{
							printf("ERROR: Memory allocation failed\n");
							exit(1);
						}
					}
					free(temp);
					/*free temp and then reallocate it to empty the temp string*/
					temp = malloc((strlen(str) + 2 - l));
					if (temp == NULL)
					{
						printf("ERROR: Memory allocation failed\n");
						exit(1);
					}
					l = 0;
					break;
					/*break if there is a much*/
				}
				else
				{
					free(temp);
					/*free temp and then reallocate it to empty the temp string*/
					temp = malloc((strlen(str) + 2 - l));
					if (temp == NULL)
					{
						printf("ERROR: Memory allocation failed\n");
						exit(1);
					}
					l = 0;
					break;
					/*break if there is a much*/
				}
			}
		}
		if (delim[j] == '\0')
			/*if there is no much comy the caracter to the temp string*/
		{
			temp[l++] = str[i];
		}
	}
	temp[l] = '\0';
	if (temp[0] != '\0')
	{
		ptr[k] = malloc((l + 1) * sizeof(char));
	/*allocate the memory to the final string*/
		if (ptr[k] == NULL)
		{
			printf("ERROR: Memory allocation failed\n");
			exit(1);
		}
		for (n = 0; temp[n] != '\0'; n++)
		/*copy the final string from the temp*/
		{
			ptr[k][n] = temp[n];
		}
		ptr[k++][n] = '\0';
		ptr[k] = NULL;
	}
	else
	{
		ptr[k] = NULL;
	}
	free(temp);
	return (ptr);
}
