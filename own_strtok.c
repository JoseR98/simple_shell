#include <stdio.h>
#include <stdlib.h>
/**
 *
 *
 *
 */
char *own_strtok(char *str, const char *delim)
{
	static int index = 0;
	char *word;
	int i = index, j = 0, k = 0, l = i, num_chars = 0;

	/* Determine number characters of each word*/
	for (; str[l] != ' '; l++)
	{
		if (str[l] == '\0')
			break;
		num_chars++;
	}
	/* Allocate memory for each word*/
	word = malloc(sizeof(char) * (num_chars + 1));
	if (word == NULL)
	{
		free(word);
		return (NULL);
	}
	while (str[i] != '\0')
	{
		j = 0;
		while (delim[j] != '\0')
		{
			if (str[i] != delim[j])
			{
				word[k] = str[i];
			}
			else
			{	
				word[k] = '\0';
				index = i + 1;
				break;
			}
			j++;
		}
		if (word[k] == '\0')
			break;
		i++;
		k++;
	}
	if (str[i] == '\0')
	{	
		word[k] = '\0';
		index = i;
	}
	return (word);
}
