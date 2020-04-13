#include "holberton.h"
/**
 *
 *
 */
void free_all(char *buffer, char **commands)
{
	free(buffer);
	free_commands(commands);
}
