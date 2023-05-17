#include "main.h"
/**
 * _strcpy - function that copies string charcters into another string
 * @dst: pointer to the destination string
 * @src: pointer to the string to be copied
 * Return: dst
 */
char *_strcpy(char *dst, const char *src)
{

	size_t i = 0;

	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
