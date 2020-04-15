#include "holberton.h"
/**
 * free_all - frees buffer and commands
 * @buffer: buffer we created from getline
 * @commands: double pointer array we created to store all commands
 * from the prompt
 * Return: void
 */
void free_all(char *buffer, char **commands)
{
	free(buffer);
	free_commands(commands);
}
