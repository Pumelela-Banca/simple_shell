# include "main.h"
/**
 * _strcat - string concatenate
 * @s1: string1
 * @s2: string2
 * Return: pointer to concatenated string
 */
char *_strcat(char *s1, const char *s2)
{
	char *v1 = s1;
	const char *v2 = s2;
	while (*v1 != '\0')
	{
		v1++;
	}
	while (*v2 != '\0')
	{
		*v1 = *v2;
		v1++;
		v2++;
	}
	*v1 = '\0';
	return (s1);
}
