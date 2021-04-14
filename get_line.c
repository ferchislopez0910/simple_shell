#include "shell.h"
/**
 * get_line - get the line objects
 * @alloc: string on line
 * @size: size of string
 * Return: string
 */
char *get_line(char *alloc, size_t size)
{
	ssize_t line = getline(&alloc, &size, stdin);

	if (line == EOF)
	{
		free(alloc);
		write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (alloc == NULL || line == 1 || line == -1)
	{
		free(alloc);
		return (NULL);
	}
	return (alloc);
}
