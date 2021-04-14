#include "shell.h"
/**
 * find_path - find the path on enviroment
 * Return: function pointer
 */
char *find_path(void)
{
	char *path_token = NULL;
	char *cp = NULL;
	int i = 0;

	while (environ[i] != NULL)
	{
		cp = _strdup(environ[i]);
		if (cp == NULL)
		{
			return (NULL);
		}
		path_token = strtok(cp, "=");
		if (_strcmp(path_token, "PATH") == 0)
		{
			free(cp);
			return (environ[i]);
		}
		i++;
		free(cp);
	}
	return (NULL);
}
/**
 * pathfound - locate the path route
 * @args: tokenize args.
 * Return: pointer function
 */
char *pathfound(char *args)
{
	struct stat dir;
	char *route = NULL;
	char *token = NULL, *hold_token = NULL;
	char *new_token = NULL;

	if (args == NULL)
		return (NULL);
	route = find_path();
	if (route == NULL)
		return (NULL);
	route = _strdup(route);
	if (route == NULL)
		return (NULL);
	token = strtok(route, " :");
	while (token != NULL)
	{
		hold_token = token;
		new_token = concat_path_with_line(args, hold_token);
		if (new_token == NULL)
		{
			free(route);
			return (NULL);
		}
		if (stat(new_token, &dir) == 0)
		{
			free(route);
			return (new_token);
		}
		token = strtok(NULL, " :");
		free(new_token);
	}
	free(route);
	return (NULL);
}
