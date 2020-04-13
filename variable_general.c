#include "holberton.h"
void free_commands(char **commands)
{
	int i;

	if (commands == NULL)
		return;
	i = 0;
	while (commands[i])
	{
		free(commands[i]);
		i++;
	}
	if (commands[i] == NULL)
		free(commands[i]);
	free(commands);
}
/**
 *
 *
 *
 */
void exit_free(char *buffer, char **commands)
{
	free(buffer);
	free_commands(commands);
	exit(EXIT_SUCCESS);
}
/**
 *
 *
 */
void show_env(char **commands, char *bufer, char **env)
{
	char **get;

	for (get = env; *get != 0; get++)
		printf("%s\n", *get);
	free(bufer);
	free_commands(commands);
	exit(EXIT_SUCCESS);
}
/**
 *
 *
 *
 */
void _clear(char *buffer, char **commands)
{
	write(STDOUT_FILENO, "\x1B[1;1H\x1B[2J", 11);
	free(buffer);
	free_commands(commands);
	exit(EXIT_SUCCESS);
}
/**
 *
 *
 *
 */
void ctrlc__handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
