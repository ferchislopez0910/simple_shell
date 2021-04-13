#include "shell.h"

char *concat_path_with_line(char *path, char *token)
{
	char *concat = NULL;
	int size_concat = _strlen_concat(path, token);
	int i = 0;
	int j = 0;

	if (path == NULL || token == NULL)
	{
		return (NULL);
	}
	concat = malloc(sizeof(char) * size_concat);
	if (concat == NULL)
	{
		return (NULL);
	}
	while (token[i] != '\0')
	{
		concat[i] = token[i];
		i++;
	}
	concat[i] = '/';
	while (path[j] != '\0')
	{
		concat[i + 1] = path[j];
		j++;
		i++;
	}
	concat[i + 1] = '\0';
	return (concat);
}

int _strlen_concat(char *path_token, char *line_token)
{
	int sz;
	int t_sz = 0;

	for (sz = 0; path_token[sz] != '\0'; sz++, t_sz++)
		;
	for (sz = 0; line_token[sz] != '\0'; sz++, t_sz++)
		;
	return (t_sz + 2);
}