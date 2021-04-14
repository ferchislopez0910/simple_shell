#include "shell.h"

void not_interactive(void)
{
		char *alloc = NULL, **line_args = NULL;
		size_t size = 0;
		int exec = 0;
		
		alloc = get_line(alloc, size);
		//printf("%s", alloc); //test the get_line.
		line_args = tokenizer(alloc);
		//printf("%s\n", command); //test the first word in get_line.
		if (builtins_exec(line_args, alloc) == 1)
		{
			if (stat(line_args[0], &dir) == 0)
				exec = execute(line_args); // -->/bin/ls
			if (stat(line_args[0], &dir) == -1) // --> ls
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
		free (alloc);
}