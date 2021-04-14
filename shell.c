#include "shell.h"
/**
 * main - function main
 *
 * Return: int.
 */

int main(void)
{
	if (isatty(STDIN_FILENO))
		simple_shell();
	else
		not_interactive();
	return (0);
}
/**
 * simple_shell - function containing the main functions
 *
 * Return: int
 */

int simple_shell(void)
{
	struct stat dir;
	char *alloc = NULL, **line_args = NULL, *command = NULL;
	size_t size = 0;
	int exec = 0;

	while (1)
	{
		write(1, "$ ", 2);
		alloc = get_line(alloc, size);
		if (alloc == NULL)
			continue;
		/*printf("%s", alloc); //test the get_line.*/
		line_args = tokenizer(alloc);
		command = line_args[0];
		/*printf("%s\n", command); //test the first word in get_line.*/
		if (builtins_exec(line_args, alloc) == 1)
		{
			if (stat(line_args[0], &dir) == 0)
				exec = execute(line_args); /* -->/bin/ls*/
			if (stat(line_args[0], &dir) == -1) /* --> ls*/
			{
				line_args[0] = pathfound(line_args[0]);
				if (line_args[0] != '\0')
					exec = execute(line_args);
				else
				{
					perror("Error");
				}
			}
		}
		free(line_args);
		free(alloc);
	}
	return (0);
}
