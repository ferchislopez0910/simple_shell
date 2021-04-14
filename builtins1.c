#include "shell.h"
/**
 * builtins_exec - array function builtins
 * @arg: args double pointer
 * @buffer: buffer of builtins
 * Return: 0 on success.
 */
int builtins_exec(char **arg, char *buffer)
{
	int i = 0;
	char *builtins_str[] = {
		"env",
		"exit"
	};
	int (*builtins_func[])(char **, char *) = {
		&execute_env,
		&execute_exit
	};
	if (arg[0] == NULL)
		return (-1);
	while (i < 2)
	{
		if (strcmp(arg[0], builtins_str[i]) == 0)
			return ((*builtins_func[i])(arg, buffer));
		i++;
	}
	return (1);
}
/**
 * execute_env - execute the enviroment
 * @arg: double pointer to array
 * @buffer: buffer of array
 * Return: 0 on success.
 */
int execute_env(char **arg, char *buffer)
{
	int i = 0;
	(void) buffer;
	(void) arg;

	while (environ[i] != NULL)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
		i++;
	}
	return (1);
}
/**
 * execute_exit - comman to exit the program
 * @arg: double pointer to function.
 * @buffer: buffer of array
 * Return: 0 on success
 */
int execute_exit(char **arg, char *buffer)
{
	free(buffer);
	free(arg);
	exit(0);
	return (1);
}
