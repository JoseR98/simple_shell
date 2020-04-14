#include "holberton.h"
/**
 *
 *
 *
 */
int main(int argc, char *argv[], char *env[])
{
	int num;
	(void)argc;
	/* general commands */
	/*            */
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, USER, 2);
	num = prompt(argv, env);
	if (num == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
