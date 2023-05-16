#include "main.h"

/**
 * _strncpy- copy string one to another
 *
 * @dest: copy src to dest
 * @src: copy to dest
 * @n: number of bytes to copy
 *
 * Return: char * (dest)
 */

char *_strncpy(char *dest, char *src, int n)
{
	int addon;

	for (addon = 0; addon < n && src[addon] != '\0'; addon++)
	{
		dest[addon] = src[addon];
	}
	for ( ; addon < n; addon++)
	{
		dest[addon] = '\0';
	}
	return (dest);
}
