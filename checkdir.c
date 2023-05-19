#include "main.h"

/**
 * checkdir - looks if name is a directory
 *
 * @name: slash 
 * @file: argument to run
 *
 * Return: directory
 */

char *checkdir(char *name, char *file)
{
	char *path = NULL;
	char buff[1024] = {0};
	DIR *dir = NULL;

	struct dirent *entity;

	if(access(file, X_OK) == 0)
                return (file);
	dir = opendir(name);
	entity = readdir(dir);
	while (entity != NULL)
	{
		strcat(buff, name);
		if (strcmp(name, "/") != 0)
			strcat(buff, "/");
		strcat(buff, entity->d_name);
		if ((strcmp(entity->d_name, ".") != 0) && 
				(strcmp(entity->d_name, "..") != 0) && 
				(entity->d_type == 4))
		{
			path = malloc((strlen(buff) + strlen(file) + 2) * sizeof(char));
			strcpy(path, buff);
			if(file[0] != '\0')
				strcat(path, "/");
			strcat(path, file);
			if(access(path, X_OK) == 0)
			{
				closedir(dir);
				return (path);
			}
			free(path);
			path = NULL;
			path = checkdir(buff, file);
			if (path != NULL)
			{
				closedir(dir);
				return (path);
			}
		}
		entity = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}
