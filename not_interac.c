#include "shell.h"
/**
 * not_interactive - do the no interactive mode
 * Return: void.
 */
void not_interactive(void)
{
	struct stat dir;
	char *alloc = NULL, **line_args = NULL;
	size_t size = 0;

	alloc = get_line(alloc, size);
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
