#include "holberton.h"
/**
 * main - basic shell recreation
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables
 * Return: 0 on exit, -1 if any failures happen
 */
int main(int argc, char *argv[], char *env[])
{
	int num;
	(void)argc;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, USER, 2);
	num = prompt(argv, env);
	if (num == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
