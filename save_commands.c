#include "holberton.h"
/**
 * save_commands - creates a double pointer array
 * @buffer: the commands from the terminal
 * Return: double pointer array of pointers
 */
char **save_commands(char *buffer)
{
	int i, w, num_words = 0;
	char *temp, **com;

	/* change \n given by getline */
	buffer[_strlen(buffer) - 1] = '\0';
	/* numbers delimiters */
	for (w = 0; buffer[w] != '\0'; w++)
	{
		if (buffer[w] != ' ')
		{
			if (buffer[w + 1] == ' ' || buffer[w + 1] == '\0')
				num_words++;
		}
	}
	if (num_words == 0)
		return (NULL);
	com = malloc(sizeof(char *) * (num_words + 1));
	if (com == NULL)
		return (NULL);
	i = 0;
	temp = strtok(buffer, " ");
	while (temp != NULL)
	{
		com[i] = malloc(_strlen(temp) + 1);
		if (com[i] == NULL)
		{
			free_commands(com);
			return (NULL);
		}
		_strncpy(com[i], temp, _strlen(temp) + 1);
		temp = strtok(NULL, " ");
		i++;
	}
	com[i] = NULL;
	return (com);
}
