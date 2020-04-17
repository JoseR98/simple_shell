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
	else if (_strcmp(commands[0], ".") == 0)
		void_point(buffer, commands);
	else if (_strcmp(commands[0], "..") == 0)
		void_point(buffer, commands);
	/* compare and execute exit*/
	else if (_strcmp(commands[0], "exit") == 0)
	{
		c_found = exit_free_child(buffer, commands);
		if (c_found == -1)
			return (-1);
	}
	/* compare and execute env */
	else if (_strcmp(commands[0], "env") == 0)
		show_env(commands, buffer, env);
	/* compare and execute clear */
	else if (_strcmp(commands[0], "clear") == 0)
		_clear(buffer, commands);
	/* validation command in each file and execute */
	else if (access(commands[0], X_OK) == 0)
		execve(commands[0], commands, env);
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
int exit_free_child(char *buffer, char **commands)
{
	int status = 0;

	if (commands[1] != NULL)
	{
		status = exit_arg(commands);
		if (status == -1)
			return (-1);
	}
	free(buffer);
	free_commands(commands);
	exit(status);
}
/**
 * void_point - void the point character when is alone
 * @buffer: the commands from the terminal
 * @commands: double pointer array we created to store all commands
 * from the prompt
 * Return: void
 */
void void_point(char *buffer, char **commands)
{
	free(buffer);
	free_commands(commands);
	exit(EXIT_SUCCESS);
}
/**
 * exit_arg - function handle exit argumments
 * @commands: double pointer array we created to store all commands
 * from the prompt
 * Return: on success number status otherwise -1
 */
int exit_arg(char **commands)
{
	int i, len = 0, num_stat = 0;
	char *num_status = NULL;

	len = _strlen(commands[1]);
	num_status = malloc(sizeof(char) * (len + 1));
	for (i = 0; commands[1][i] != '\0'; i++)
	{
		if (commands[1][i] >= '0' && commands[1][i] <= '9')
			num_status[i] = commands[1][i];
		else
			break;
	}
	if (commands[1][i] != '\0')
	{
		free(num_status);
		return (-1);
	}
	num_status[i] = '\0';
	num_stat = _atoi(num_status);
	free(num_status);
	return (num_stat);
}
/**
 * _atoi - function that convert a string to an integer.
 * @s: is a parameter
 * Return: integer
 */
int _atoi(char *s)
{
	int sign = 1;
	int i;
	unsigned int num = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
			num = (num * 10) + (s[i] - '0');
		else if (num > 0)
			break;
	}
	return (num * sign);
}
