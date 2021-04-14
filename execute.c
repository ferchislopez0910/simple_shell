#include "shell.h"
/**
 * execute - creates a new process id and execute command
 * @line_args: args to execute
 * Return: 0 on success
 */
int execute(char **line_args)
{
	pid_t pid;

	if (line_args == NULL)
	{
		return (-1);
	}
	pid = fork();
	wait(NULL);
	if (pid == -1)
	{
		perror("pid Error");
		return (-1);
	}
	else if (pid == 0)
	{
		execve(line_args[0], line_args, environ);
		return (0);
	}
	return (-1);
}
