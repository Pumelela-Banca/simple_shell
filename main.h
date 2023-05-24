#ifndef MAIN_H
#define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
#include <string.h>
# include <dirent.h>

extern char **environ;
extern char **evar_;


typedef struct built_in_
{
	char *name;
	void (*fun)(char *cmds[]);
} ff_t;

typedef struct environvar
{
        char *name;
        char *value;

        struct environvar *next;
}
_var;

int _atoi(char *s);
char *getpath(char *cmd);
void execfile(char *cmds[]);
char *_strdup(const char *s1);
void _free(char *cmds[]);
int _strcmp(const char *str1, const char *str2);
char *_strdup(const char *s1);
char *_strcat(char *s1, const char *s2);
char *_strcpy(char * dst, const char * src);
size_t _strlen(const char *s);
char *checkdir(char *name, char *file);
int printstr(char *s);
void print_error(int *num_cy, char *argv[], char *cmds[]);
char **envtokenise(char **env_init);
char **tokenise(char *buff);
void _setenv(char *cmds[]);
char *_getenv(char *name);
void _exit_(char *cmds[]);
void free_list(_var *head);
char *look_in_env(_var *head, char *name);
void _clear(char *cmds[]);
void _exit_(char *cmds[]);
void _cd(char *cmds[]);
void _cd_home(char *cmds[]);
void _cd_dir(char *cmds[]);
void _cd_prev(char *cmds[]);
int _which(char *cmds[]);
void _env(char *cmds[]);
void _env_var_print(char *cmds[]);
int file_exec(char *cmds[], char *argv[], int *count);
char *_shellprint(void);
int _putchar(char c);
int print_num(int n);
int printstr(char *s);
char **_envset(char *cmds[]);
void _env_modify(char *cmds[]);
void _setenv(char *cmds[]);
char ** _env_delete(char *cmds[]);
void _unsetenv(char *cmds[]);
void terminal(char *argv[]);
char *readfile(char *filepath);
void no_terminal(char **argv);
char *get_input(void);
char *removespace(char *s);
#endif
