#include "main.h"

/**
 * readfile - reads file as input
 *
 * @filepath: path of file
 *
 * Return: file contents
 */

char *readfile(char *filepath)
{
	int i = 0, j = 0, fd;
	char *buff = NULL;

	buff = malloc(1024 * sizeof(char));
	if (buff == NULL)
	{
		perror("can't allocate memory");
		return NULL;
	}
	if ((fd = open(filepath, O_RDONLY)) == -1)
	{
		perror("Error opening file");
		free(buff);
		return NULL;
	}
	j = read(fd, buff, 1023);
	if (j == -1)
	{
		perror("Error reading file");
		close(fd);
		free(buff);
		return NULL;
	}
	buff[j] = '\0';
	while (buff[i] != '\0')
	{
		if(buff[i] == '\n')
		{
			buff[i] = '\0';
			break;
		}
		i++;
	}
	close(fd);
	return (buff);
}
