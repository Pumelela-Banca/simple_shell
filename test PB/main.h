#ifndef MAIN_H
#define MAIN_H

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

void print_error(cals_t *env_info, char *err_msg);
int printstr(char *s);
int _putchar(char c);
char *_getenv(char *name, char *envp[]);
int look_ind(char *str1, char *str2);
char *dup_s(char *str, int c);
int _strlen(char *s);
#endif
