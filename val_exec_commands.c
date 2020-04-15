#include "holberton.h"
/**
 * val_execute_command - free and execute gerenal commands
 * @commands: double pointer array we created to store all commands
 * @buffer: buffer array created by new line
 * @env: environment variables from your login
 * Return: -1 if any failures happen
 */
int val_execute_command(char **commands, char *buffer, char **env)
{
	int c_found = 0;

	if (commands == NULL)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	/* compare and execute exit*/
	else if (_strcmp(commands[0], "exit") == 0)
		exit_free_child(buffer, commands);
	/* compare and execute env */
	else if (_strcmp(commands[0], "env") == 0)
		show_env(commands, buffer, env);
	/* compare and execute clear */
	else if (_strcmp(commands[0], "clear") == 0)
		_clear(buffer, commands);
	/* validation command in each file and execute */
	else if (access(commands[0], X_OK) == 0)
		execve(commands[0], commands, NULL);
	else
	{
		c_found = concat_commands(commands, buffer, env);
		if (c_found == -1)
			return (-1);
	}
	return (0);
}
/**
 * exit_free_child - free and execute exit process child
 * @buffer: the commands from the terminal
 * @commands: double pointer array we created to store all commands
 * from the prompt
 * Return: void
 */
void exit_free_child(char *buffer, char **commands)
{
	free(buffer);
	free_commands(commands);
	exit(EXIT_SUCCESS);
}
