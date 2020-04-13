#include "holberton.h"
/**
 * _strcmp - function that compares two strings.
 * @s1: is a parameter
 * @s2: is a parameter
 * Return: the value
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == '\0')
			return (0);
	}
	return (1);
}
/**
 * _strncpy - function that copies a string.
 * @dest: is a parameter
 * @src: is a parameter
 * @n: is a parameter
 * Return: Always 0 (Success)
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		if (i < n)
			dest[i] = src[i];
	}
	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
/**
 * _strlen - function that returns the length of a string
 * @s: is a parameter
 * Return: length
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}
/**
 *
 *
 */
void end_of_file(char *buffer)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}
