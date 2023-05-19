#ifndef MAIN_H
#define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <dirent.h>
# include <stdlib.h>

extern char **environ;

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
} _var;


char *getpath(char *cmd, char *envp[]);
void execfile(char *cmds[], char *envp[]);
char *_strdup(const char *s1);
void _free(char *cmds[]);
int _strcmp(const char *str1, const char *str2);
char *_strdup(const char *s1);
char *_strcat(char *restrict s1, const char *restrict s2);
char *_strcpy(char * dst, const char * src);
void print_error(int *num_cy, char *argv[], char *cmds[]);
void _clear(char *envp[], char *cmds[]);
void _env(char *envp[], char *cmds[]);
void _exit_(char *envp[], char *cmds[]); /*might need to include*/
int print_num(int n);
int printstr(char *s);
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *dst, const char *src);
size_t _strlen(const char *s);
char *_strdup(const char *s1);
void _which(char *envp[], char *cmds[]);
void execfile(char *cmds[], char *envp[]);
char *_shellprint(void);
char *checkdir(char *name, char *file);
void no_terminal(char **argv, char **envp);
void terminal(char *argv[], char *envp[]);
char *get_input(void);
char *readfile(char *filepath);
int file_exec(char *envp[], char *cmds[], char *argv[], int *count);
int _putchar(char c);
char **tokenise(char *buff);
void free_list(_var *head);
void listpopulate(_var *head, char *new[]);
char *_getenv(char *name);
char **envtokenise(void);
char *look_in_env(_var *head, char *name);
char *getpath(char *cmd, char *envp[]);
void execfile(char *cmds[], char *envp[]);
char *_strdup(const char *s1);
void _free(char *cmds[]);
int _strcmp(const char *str1, const char *str2);
char *_strdup(const char *s1);
char *_strcat(char *restrict s1, const char *restrict s2);
char *_strcpy(char * dst, const char * src);
size_t _strlen(const char *s);
char *checkdir(char *name, char *file);
void _free(char *cmds[]);
int printstr(char *s);
void print_error(int *num_cy, char *argv[], char *cmds[]);
int file_exec(char *envp[], char *cmds[], char *argv[], int *count);
void free_list(_var *head);
char **envtokenise(void);
void _cd(char *envp[], char *argv[], char *cmds[]);
void _env_var_print(char *envp[], char *cmds[]);


#endif
