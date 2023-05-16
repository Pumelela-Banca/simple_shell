#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * _getenv: uses envp[] to search envoronment variable
 *
 * @name: variable to get
 *
 * Return: value of variable
 */

char *_getenv(char *name, char **envp)
{
	int i, c, count;
	char *val;

	c = strlen(name);

	count = 0;
	while (envp[count] != '\0')
	{
		i = look_ind(name, envp[count]);
		if (i == 1)
		{
			val = dup_s(envp[count], c);
			return (val);
		}
		count++;
	}
}

/**
 * dup_s - duplicates string from index to end
 *
 * @str: string
 * @c: start index
 *
 * Return: new string
 */

char *dup_s(char *str, int c)
{
	char *val;
	int i, check, start;

	i = 0;
	val = malloc((strlen(str) - c - 1) * sizeof(char *) + 1);
	if (val == NULL)
	{
		perror("Memory allocation fail");
		exit(0);
	}
	check = 0;
	start = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
		{
			check = 1;
			i++;
			continue;
		}
		if (check == 1)
		{
			val[start] = str[i];
			start++;
		}
		i++;
	}
	val[i] = '\0';
	return (val);
}

/**
 * look_ind: looks for index match in two srings
 *
 * @str1: short string
 * @str2: long string
 *
 * Return: 1 for match 0 for no match
 */

int look_ind(char *str1, char *str2)
{
	int i, c;

	c = 0;
	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] == str2[c])
		{
			c++;
			continue;
		}
		else
			return (0);
	}
	if (str2[i] == '=')
		return (0);
	return (1);
}

void main(int ac, char **av, char **env)
{
    /*printf("%s", env);*/
    printf("---%s---", _getenv("PATH", env));
	printf("====%s====", getenv("PATH"));
}
