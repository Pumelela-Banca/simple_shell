# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
#include <string.h>
char *getpath(char *cmd, char *envp[]);
void execfile(char *cmds[], char *envp[]);
char *_strdup(const char *s1);
void _free(char *cmds[]);
/**
 *  _exit_ - exit
 *  @envp: *envp[]
 *  @cmds: *cmds[][]
 */
void _exit_(char *envp[], char *cmds[])
{
        _free(cmds);
        exit(0);
}
/**
 *  _cd - exit
 *  @envp: *envp[]
 *  @cmds: *cmds[][]
 */
void _cd(char *envp[], char *cmds[])
{
        if (chdir(cmds[1]) != 0)
        {
                _free(cmds);
                perror("change directory failed");
        }
        _free(cmds);
}
/**
 *  _which - exit
 *  @envp: *envp[]
 *  @cmds: *cmds[][]
 */
void _which(char *envp[], char *cmds[])
{
        int i = 1;
        char * path = NULL;
        while(cmds[i] != NULL)
        {
                path = getpath(cmds[i], envp);
                printf("%s\n", path);
                free(path);
                i++;
        }
        _free(cmds);
}
/**
 *  _env - exit
 *  @envp: *envp[]
 *  @cmds: *cmds[][]
 */
void _env(char *envp[], char *cmds[])
{
       int i = 0;
       while (envp[i] != NULL)
       {
               printf("%s\n", envp[i]);
               i++;
       }
       _free(cmds);
}
/**
 *  _env_var_printt - exit
 *  @envp: *envp[]
 *  @cmds: *cmds[][]
 */
void _env_var_print(char *envp[], char *cmds[])
{
        char *envvar = NULL;
        envvar = cmds[1];
        envvar++;
        printf("%s\n", getenv(envvar));
        _free(cmds);
}
/**
 *  file_exec - exit
 *  @envp: *envp[]
 *  @cmds: *cmds[][]
 */
void file_exec(char *envp[], char *cmds[])
{
        char *path = NULL;
        pid_t pid = fork();
        if (pid == -1)
        {
                perror("fork failed");
                _free(cmds);
                exit(1);
        }
        else if (pid == 0)
        {
                path = getpath(cmds[0], envp);
                cmds[0] = _strdup(path);
                execfile(cmds, envp);
                perror("execve failed");
                exit(1);
        }
        else
        {
                wait(NULL);
        }
        _free(cmds);
}
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
/**
 * _strcpy - function that copies string charcters into another string
 * @dst: pointer to the destination string
 * @src: pointer to the string to be copied
 * Return: dst
 */
char *_strcpy(char * dst, const char * src)
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
/**
 * _strcat - string concatenate
 * @s1: string1
 * @s2: string2
 * Return: pointer to concatenated string
 */
char *_strcat(char *restrict s1, const char *restrict s2)
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
                return 0;
        else if (*str1 == '\0')
                return -1;
        else if (*str2 == '\0')
                return 1;
        return (unsigned char)(*str1) - (unsigned char)(*str2);
}
/**
 * _strdup - string duplicate
 * @s1: input string
 * Return: resulted string
 */
char *_strdup(const char *s1)
{
        char *str = NULL;
        int i = 0;
        str = malloc ((_strlen(s1) + 1) * sizeof(char));
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

/**
 * printstr - prints a string to given stdout
 *
 * @s: given string
 *
 * Return: 1 for success
 */

int printstr(char *s)
{
	int count;

	for (count = 0; s[count] != '\0'; count++)
	{
		_putchar(s[count]);
	}
	return (1);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
char *getpath(char *cmd, char *envp[])
{
        char *buff = NULL, *token = NULL;
        char *path = getenv("PATH");
        if (access(cmd, X_OK) == 0)
                return(cmd);
        buff = malloc((_strlen("/usr") + _strlen(cmd) + 2) * sizeof(char));
        if (buff == NULL)
        {
                        perror("Error: can't allocate buffer space");
                        exit(1);
        }
        _strcpy(buff, "/usr");
        if(cmd[0] != '/')
                _strcat(buff,"/");
        _strcat(buff, cmd);
        if (access(buff, X_OK) == 0)
                return(buff);
        free(buff);
        token = strtok(path, ":");
        do {
                buff = malloc((_strlen(token) + _strlen(cmd) + 2) * sizeof(char));
                if (buff == NULL)
                {
                        perror("Error: can't allocate buffer space");
                        exit(1);
                }
                _strcpy(buff, token);
                _strcat(buff,"/");
                _strcat(buff, cmd);
                if (access(buff, X_OK) == 0)
                        return(buff);
                else
                {
                        token = strtok(NULL, ":");
                }
        } while (token != NULL);
        perror("Error");
        return NULL;
}

char **tokenise(char *buff)
{
        char *path = NULL;
        char *delim = " ";
        char *token = NULL;
        int i = 0, j = 0;
        char **cmds = malloc (10 * sizeof(char *));
        token = strtok(buff, delim);
        do
        {
                cmds[i] = _strdup(token);
                if (cmds[i] == NULL)
                {
                        while (j < i)
                        {
                                free(cmds[j]);
                                j++;
                        }
                        free(cmds);
                        exit(1);
                }
                token = strtok(NULL, delim);
                i++;
        } while(token != NULL);
        cmds[i] = NULL;
        free(buff);
        return(cmds);
}
void execfile(char *cmds[], char *envp[])
{
        execve(cmds[0], cmds, envp);
}
char *_shellprint(void)
{
        char *buff = NULL;
        size_t n = 1024, i = 0;
        buff = malloc(n * sizeof(char));
        if (buff == NULL)
        {
                perror("Error: can't allocate memo");
                exit(1);
        }
        printf("myShell$ ");
        getline(&buff, &n, stdin);
        while (buff[i] != '\0')
        {
                if(buff[i] == '\n')
                {
                        buff[i] = '\0';
                        break;
                }
                i++;
        }
        /*buff[strcspn(buff, "\n")] = '\0';*/
        return (buff);
}
void _free(char *cmds[])
{
        int i = 0;
        while (cmds[i] != NULL)
        {
                free(cmds[i]);
                i++;
        }
        free(cmds);
}
int main(int argc, char *argv[], char *envp[])
{
        int j = 0;
        char **cmds = NULL, *buff = NULL;
        do {
                buff = _shellprint();
                cmds = tokenise(buff);
                if (_strcmp(cmds[0], "exit") == 0)
                        _exit_(envp, cmds);
                else if (_strcmp(cmds[0], "cd") == 0)
                {
                        _cd(envp, cmds);
                        continue;
                }
                else if (_strcmp(cmds[0], "which") == 0)
                {
                        _which(envp, cmds);
                        continue;
                }
                else if (_strcmp(cmds[0], "env") == 0)
                {
                        _env(envp, cmds);
                        continue;
                }
                else if ((_strcmp(cmds[0], "echo") == 0) && (cmds[1][0] == '$'))
                {
                        _env_var_print(envp, cmds);
                        continue;
                }
                else
                {
                        file_exec(envp, cmds);
                        continue;
                }
                j++;
        } while (j < 10);
        return 0;
}







