#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

struct stat dir;
extern char **environ;

int simple_shell(void);
char *get_line(char *alloc, size_t size);
char **tokenizer(char *alloc);
int execute(char **line_args);

char *find_path(void);
char *pathfound(char *args);

int _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *src);

char *concat_path_with_line(char *args, char *token);
int _strlen_concat(char *path, char *token);

int builtins_exec(char **arg, char *buffer);
int execute_env(char **arg, char *buffer);
int execute_exit(char **arg, char *buffer);

#endif /**SHELL_H*/