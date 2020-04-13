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
	char *var[3] = {"exit", "env", "clear"};
	/*            */
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, USER, 2);
	num = prompt(argv, env, var);
	if (num == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
