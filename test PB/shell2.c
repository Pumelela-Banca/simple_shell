# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

char *getpath(char *cmd, char *envp[])
{
        char *buff = NULL, *token = NULL;
        char *path = getenv("PATH");
        token = strtok(path, ":");
        do {
                buff = malloc((strlen(token) + strlen(cmd) + 2) * sizeof(char));
                if (buff == NULL)
                {
                        perror("Error: can't allocate buffer space");
                        exit(1);
                }
                strcpy(buff, token);
                strcat(buff,"/");
                strcat(buff, cmd);
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

char *_getenv(char *ind, char *envp[])
{
	char *value;
	int i = 0;
	int size;
	
	size = _strlen(ind);
	while (*envp != '\0')
	{
		while (*ind != '\0')
		{
			if (envp[i] != ind[i])
			{

				
}
char **tokenise(char *buff)
{
        char *path = NULL;
  char *delim = " ";
        char *token = NULL;
        int i = 0;
        char **cmds = malloc(10 * sizeof(char *));
        token = strtok(buff, delim);
        do
        {
                cmds[i] = strdup(token);
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
        size_t n = 1024;
	int rez;

        buff = malloc(n * sizeof(char));
        if (buff == NULL)
        {
                perror("Error: can't allocate memo");
                exit(1);
        }
        printf("myShell$ ");
        rez = getline(&buff, &n, stdin);
        if (rez == -1)
	{
		free(buff);
		exit(1);
	}
	buff[strcspn(buff, "\n")] = '\0';
        return (buff);
}
int main(int argc, char *argv[], char *envp[])
{
        int i = 0, j = 0;
        char **cmds = NULL;
        char *buff = NULL;
        char *path = NULL;
        char *envvar = NULL;
        do {
                buff = _shellprint();
                cmds = tokenise(buff);
                if (strcmp(cmds[0], "exit") == 0)
                {
                        break;
                }
                else if (strcmp(cmds[0], "cd") == 0)
                {
                        if (chdir(cmds[1]) == 0)
                                continue;
                        else
                        {
                                perror("chdir failed");
                                continue;
                        }
                }
                else if (strcmp(cmds[0], "which") == 0)
                {
                        i = 1;
                        while(cmds[i] != NULL)
                        {
                                path = getpath(cmds[i], envp);
                                printf("%s\n", path);
                                free(path);
                                i++;
                        }
                }
                else if (strcmp(cmds[0], "env") == 0)
                {
                        i = 0;
                        while (envp[i] != NULL)
                        {
                                printf("%s\n", envp[i]);
                                i++;
                        }
                        continue;
                }
                else if ((strcmp(cmds[0], "echo") == 0) && (cmds[1][0] == '$'))
                {
                        envvar = cmds[1];
                        envvar++;
                        printf("%s\n", getenv(envvar));
                        continue;
                }
                else
                {
                        pid_t pid = fork();
                        if (pid == -1)
                        {
                                perror("fork failed");
                                exit(1);
                        }
                        else if (pid == 0)
                        {
                                path = getpath(cmds[0], envp);
                                cmds[0] = strdup(path);
                                execfile(cmds, envp);
                                perror("execve failed");
                                exit(1);
                                free (buff);
                                buff = NULL;
                        }
                        else
                        {
                                wait(NULL);
                                continue;
                        }
                }
                j++;
        } while (j < 10);
        return 0;
}
