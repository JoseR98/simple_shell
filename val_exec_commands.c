#include "holberton.h"

int val_execute_command(char **commands, char *buffer, char **var, char **env)
{
	int c_found = 0;

	if (commands == NULL)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	/* compare and execute exit*/
	else if (_strcmp(commands[0], var[0]) == 0)
		exit_free(buffer, commands);
	/* compare and execute env */
	else if (_strcmp(commands[0], var[1]) == 0)
		show_env(commands, buffer, env);
	/* compare and execute clear */
	else if (_strcmp(commands[0], var[2]) == 0)
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
