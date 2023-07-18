#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LEN 1024
#define PATH_DELIMITER ":"
#define BUFFER_SIZE 1024
#define MAX_ARGS 10
#define MAX_COMMAND_LENGTH 100

/* Global environemnt */
extern char **environ;

/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/**
 * struct alias_s - A new struct defining aliases.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: A pointer to another struct alias_s.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

void execute(char *command, char *args[]);
int splitline(char *line, char *args[]);
void readLine(int inputFile, char *line, int maxLen);
void nonInteractive(void);
void Interactive(void);
char *findExecutable(char *command);
void changeDir(char *path, char *previous_dir);
int _strlen(const char *s);
char *strdup_custom(const char *source);
char *strncpy_custom(char *destination, const char *source, size_t num);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
int alias(char **args, char __attribute__((__unused__)) **front);
void free_alias_list(alias_t *head);
void print_alias(alias_t *alias);
alias_t *add_alias_end(alias_t **head, char *name, char *value);
void set_alias(char *var_name, char *value);
int shell_exit(char **args, char **front);
char **split_line(char *line);
int _env(char **args, char __attribute__((__unused__)) **front);
int _setenv(char **args, char __attribute__((__unused__)) **front);
int _unsetenv(char **args, char __attribute__((__unused__)) **front);
char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);
char *_getline(void);
void free_args(char **args, char **front);
int create_error(char **args, int err);

#endif
