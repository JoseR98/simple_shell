#ifndef _HOLBERTON_H
#define _HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdarg.h>
#define USER "$ "

/** prompt */
int prompt(char *argv[], char *env[], char *var[]);
/** function that saves commands in an array*/
char **save_commands(char *buffer);
/**own strtok function*/
char *own_strtok(char *str, const char *delim, int *index);
/**validation and execute commands**/
int val_execute_command(char **commands, char *buffer, char **var, char **env);
/** free double pointer */
void free_commands(char **commands);
/* exit prompt */
void exit_free(char *buffer, char **commands);
/* show environment */
void show_env(char **commands, char *bufer, char **env);
/* clear screen */
void _clear(char *buffer, char **commands);
/* send signal */
void ctrlc__handler(int sig);
/* commands not found */
void c_not_found(char **commands, char *buffer, char **argv, int num_command);
/* end of file */
void end_of_file(char *buffer);
/* free all */
void free_all(char *buffer, char **commands);

/** FUNCTIONS AUXILIAR */
/* copies a string.*/
int _strcmp(char *s1, char *s2);
/* copies n characteres of string */
char *_strncpy(char *dest, char *src, int n);
/* length of a string */
int _strlen(char *s);

/**FUNCTIONS ENVIRONMENT */
int concat_commands(char **commands, char *buffer, char **env);
char **get_path_dir(char **commands, char **env);
char *get_path_str(char **env);

#endif
