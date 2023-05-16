/**
 * _strlen - function to comput the length of a given string
 * @s: input string
 * Return: length of string
 */
size_t _strlen(const char *s)
{
	size_t len = 0;

	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}
