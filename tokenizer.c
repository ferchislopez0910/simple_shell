#include "shell.h"
/**
 * tokenizer - function that tokenizer
 * @alloc: Pointer of line arguments.
 * Return: pointer char.
 */
char **tokenizer(char *alloc)
{
	char **tokens = NULL;
	char *aux = NULL;
	int i, j;

	j = count_words(alloc);

	tokens = malloc(sizeof(char *) * (j + 1));
	if (tokens == NULL)
	{
		return (NULL);
	}
	aux = strtok(alloc, " \t\n");
	for (i = 0; aux != NULL; i++)
	{
		tokens[i] = aux;
		aux = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;
	return (tokens);
}
/**
 * count_words - counter words
 * @alloc: Pointer of line arguments
 * Return: int.
 */

int count_words(char *alloc)
{
	int i = 0;
	int count = 0;
	char *cp = alloc;

	if (alloc != '\0')
	{
		while (alloc[i] != '\0')
		{
			if ((alloc[i] == ' ') || (alloc[i] == '\n') || (alloc[i] == '\t'))
			{
				if ((alloc[i - 1] != ' ') && (cp[0] != alloc[i]))
				{
					count++;
				}
				if ((alloc[i - 1] != '\n') && (cp[0] != alloc[i]))
				{
					count++;
				}
				if ((alloc[i - 1] != '\t') && (cp[0] != alloc[i]))
				{
					count++;
				}
			}
			i++;
		}
	}
	return (count);
}
