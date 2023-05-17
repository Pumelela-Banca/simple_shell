#include "main.h"
/**
 * _strdup - string duplicate
 * @s1: input string
 * Return: resulted string
 */
char *_strdup(const char *s1)
{
	char *str = NULL;
	int i = 0;

	str = malloc((_strlen(s1) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
