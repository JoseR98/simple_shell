#include "holberton.h"
/**
 *
 *
 *
 *
 */
int prompt(char *argv[], char *env[], char *var[])
{
	char *buffer = NULL, **commands;
	int num_command = 0, status, c_found = 0;
	size_t size = 0;
	ssize_t ret_getl;
	pid_t pid;
	(void)argv;

	signal(SIGINT, ctrlc__handler);	/**Signal for ctrl + c*/
	while ((ret_getl = getline(&buffer, &size, stdin)))
	{
		if (ret_getl == EOF)
			end_of_file(buffer);
		num_command++;
		commands = save_commands(buffer); /**function tha splits buffer in words*/
		pid = fork();
		if (pid == -1)	/** validate if process creation works*/
			perror("Fork");
		if (pid == 0)	/** validate if it's child*/
		{
			c_found = val_execute_command(commands, buffer, var, env);
			if (c_found == -1)
				c_not_found(commands, buffer, argv, num_command);
		}
		else	/** its parent*/
		{
			wait(&status);
			if (commands == NULL)
				free_all(buffer, commands);
			/* free buffer, commands and execute exit father */
			else if (_strcmp(commands[0], var[0]) == 0)
				exit_free(buffer, commands);
			else
				free_all(buffer, commands);
		}
		buffer = NULL;
		size = 0;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, USER, 2);
	}
	return (-1);
}
