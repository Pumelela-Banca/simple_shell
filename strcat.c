/**
 * _strcat - string concatenate
 * @s1: string1
 * @s2: string2
 * Return: pointer to concatenated string
 */
char *_strcat(char *restricts1, const char *restricts2)
{
	char *restrict v1 = s1;
	const char *restrict v2 = s2;
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
