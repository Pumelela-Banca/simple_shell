/**
 *  _strcmp - function to compare two strings
 *  @str1: first string
 *  @str2: second string
 *  Return: 0 if the strings are equalst
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 == '\0')
		return (0);
	else if (*str1 == '\0')
		return (-1);
	else if (*str2 == '\0')
		return (1);
	return ((unsigned char)(*str1) - (unsigned char)(*str2));
}
