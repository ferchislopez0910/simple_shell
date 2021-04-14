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
	char *alloc = NULL, **line_args = NULL;
	size_t size = 0;

	while (1)
	{
		write(1, "$ ", 2);
		alloc = get_line(alloc, size);
		if (alloc == NULL)
			continue;

		line_args = tokenizer(alloc);

		if (builtins_exec(line_args, alloc) == 1)
		{
			if (stat(line_args[0], &dir) == 0)
				execute(line_args);
			if (stat(line_args[0], &dir) == -1)
			{
				line_args[0] = pathfound(line_args[0]);
				if (line_args[0] != '\0')
					execute(line_args);
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
