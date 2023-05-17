#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

extern char **environ;

char *getpath(char *cmd, char *envp[]);
void execfile(char *cmds[], char *envp[]);
char *_strdup(const char *s1);
void _free(char *cmds[]);
int _strcmp(const char *str1, const char *str2);
char *_strdup(const char *s1);
char *_strcat(char *restrict s1, const char *restrict s2);
char *_strcpy(char * dst, const char * src);
void print_error(cals_t *env_info, char *err_msg);
void _env_var_print(char *envp[], char *cmds[]);
void _cd(char *envp[], char *cmds[]);
void _clear(char *envp[], char *cmds[]);
void _env(char *envp[], char *cmds[]);
void _exit_(char *envp[], char *cmds[]); /*might need to include*/
void file_exec(char *envp[], char *cmds[]);
int print_num(int n);
int printstr(char *s);
char *_strcat(char *restrict s1, const char *restrict s2);
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *dst, const char *src);
size_t _strlen(const char *s);
char *_strdup(const char *s1);
void _which(char *envp[], char *cmds[]);


/**
 * struct environvar - linked list of enviroment variables
 * @name: index
 * @value: value
 * @envirovar: next variable
 */

typedef struct environvar
{
        char *name;
        char *value;
        struct environvar *next;
}
_var;

/*struct env_info -  contains information on current environment
 * 
 * @fmane: launced file name
 * @nm_cls: number of commands
 * @sh_arg: shell argument
 */

typedef struct info
{
	char *fname;
	int nm_cls;
	char *sh_arg;
} cals_t;

#endif
