#include "holberton.h"
/**
 * prompt - display the prompt
 * @argv: argument vector
 * @env: environment variables from your login
 * Return: -1 if any failures happen
 */
int prompt(char *argv[], char *env[])
{
	char *buffer = NULL, **commands = NULL;
	int num_com = 0, status, c_found = 0, err_stat = 0, *exit_stat = &err_stat;
	size_t size = 0;
	ssize_t ret_getl;
	pid_t pid;

	signal(SIGINT, ctrlc__handler);	/**Signal for ctrl + c*/
	while ((ret_getl = getline(&buffer, &size, stdin)))
	{
		if (ret_getl == EOF)
			end_of_file(buffer, *exit_stat);
		num_com++;
		commands = save_commands(buffer); /**function tha splits buffer in words*/
		pid = fork();
		if (pid == -1)	/** validate if process creation works*/
			fork_fail(buffer, commands);
		if (pid == 0)	/** validate if it's child*/
		{
			c_found = val_execute_command(commands, buffer, env);
			if (c_found == -1)
				c_not_found(commands, buffer, argv, num_com);
		}
		else	/** its parent*/
		{
			wait(&status);
			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
				*exit_stat = WEXITSTATUS(status);
			if (commands == NULL)
				free_all(buffer, commands);
			else if (_strcmp(commands[0], "exit") == 0) /*free and execute exit father*/
				exit_free(buffer, commands, *exit_stat);
			else
				free_all(buffer, commands);
		}
		size = 0;
		buffer = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, USER, 2);
	}
	return (-1);
}
/**
 * fork_fail - funtion that handles a fork fail
 * @buffer: buffer array created by new line
 * @commands: double pointer array we created to store all commands
 * Return: void
 */
void fork_fail(char *buffer, char **commands)
{
	perror("Error:");
	free(buffer);
	free_commands(commands);
	exit(EXIT_FAILURE);
}
