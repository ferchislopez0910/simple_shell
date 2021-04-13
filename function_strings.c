#include "shell.h"

int _strncmp(char *s1, char *s2, size_t n)
{
    while ( n && *s1 && (*s1 == *s2))
    {
        ++s1;
        ++s2;
        --n;
    }
    if (n == 0)
        return (0);
    else
    {
        return (*(char *)s1 - *(char *)s2);
    }
}

int _strlen(char *s)
{
	int len;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
		{
			break;
		}
		s1++;
		s2++;
	}
	return (*(char *)s1 - *(char *)s2);
}

char *_strdup(char *src)
{
	char *str = NULL, *p = NULL;
    int len = 0;

    while (src[len])
	{
        len++;
	}
    str = malloc(len + 1);
    p = str;
    while (*src)
        *p++ = *src++;
    *p = '\0';
    return (str);
}