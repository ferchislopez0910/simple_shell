#include "shell.h"

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
                return((*builtins_func[i])(arg, buffer));
            i++;
        }
        return (1);
}


int execute_env(char **arg, char * buffer)
{
    (void) buffer;
    int i = 0; 
    char **en = environ;
    char n = '\n';
    while (*en != NULL)
    {
        write(1, *en, strlen(*en));
        write(1, &n, 1);
        *en++;
    }
    return(1);
}

int execute_exit(char **arg, char *buffer)
{
        free(buffer);
        free(arg);
        exit(0);
        return (1);
}