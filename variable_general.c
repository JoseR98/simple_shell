#include "holberton.h"
/**
 * free_commands - frees all the memory associated with a double pointer
 * @commands: the double pointer to free
 * Return: void
 */
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
 * exit_free - frees the buffer and commands we created from the
 * getline function
 * @buffer: buffer we created from getline
 * @commands: the double pointer to free
 * @error: is number of status
 * Return: void
 */
void exit_free(char *buffer, char **commands, int error)
{
	free(buffer);
	free_commands(commands);
	exit(error);
}
/**
 * show_env - frees the buffer and commands we created from the
 * getline function, prints the env
 * @commands: double pointer array we created to store all commands
 * from the prompt
 * @buffer: buffer we created from getline
 * @env: environment variables from your login
 * Return: void
 */
void show_env(char **commands, char *buffer, char **env)
{
	char **get;

	for (get = env; *get != 0; get++)
	{
		write(STDOUT_FILENO, *get, _strlen(*get));
		write(STDOUT_FILENO, "\n", 1);
	}
	free(buffer);
	free_commands(commands);
	exit(EXIT_SUCCESS);
}
/**
 * _clear - function that clear the terminal screen
 * @buffer: buffer we created from getline
 * @commands: environment variables from your login
 * Return: void
 */
void _clear(char *buffer, char **commands)
{
	write(STDOUT_FILENO, "\x1B[1;1H\x1B[2J", 11);
	free(buffer);
	free_commands(commands);
	exit(EXIT_SUCCESS);
}
/**
 * ctrlc__handler - handles signals and write the prompt
 * @sig: signal to handle
 * Return: void
 */
void ctrlc__handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
