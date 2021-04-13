#include "shell.h"

char **tokenizer(char *alloc)
{
	char **tokens = NULL;
	char *aux = NULL;
	int i, j;

	for (j = 0; alloc[j] != '\0'; j++)
		;
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
