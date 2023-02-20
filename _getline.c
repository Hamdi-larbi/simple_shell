#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#define temp_size 1024

/**
 * _getline - custom getline function
 * @lineptr: address of the first character position
 * where the input string will be stored
 * @n: the address of the variable that holds the size of the input buffer
 * @stream: the input file handle
 * Return: the count of readed caracters
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *temp = *lineptr;
	int c;
	size_t size = *n;
	size_t count = 0;

	if (*lineptr == NULL)
	{
		temp = malloc(temp_size);
		if (temp == NULL)
			return (-1);
		size = temp_size;
	}
	while ((c = getc(stream)) != EOF)
	{
		if (count + 1 >= size)
		{
			size *= 2;
			temp = realloc(temp, size);
			if (temp == NULL)
				return (-1);
		}
		temp[count++] = c;
		if (c == '\n')
			break;
	}
	temp[count] = '\0';
	if (c == EOF && count == 0)
		return (-1);
	*n = size;
	*lineptr = temp;
	return (count);
}
