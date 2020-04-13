#include "holberton.h"
/**
 * 
 * 
 * 
 */
char *own_itoa(int num_command)
{
    int result = num_command,digit = 1, count = 0, j;
    char *str_num = NULL;
    while (result / 10)
    {
        count++;
        digit *= 10;
        result /= 10;
    }
    count++;
    str_num = malloc(sizeof(char) * (count + 1));
    if (str_num == NULL)
        return (NULL);
    j = 0;
    while (digit > 0)
    {
        result = num_command / digit;
        str_num[j] = result + '0';
        num_command = num_command - (result * digit);
        digit /= 10;
        j++;
    }
    str_num[j] = '\0';
    return (str_num);
}
/**
 *
 *
 *
 *
 */
void c_not_found(char **commands, char *buffer, char **argv, int num_command)
{
    char *num_com;
    (void)argv;
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
    num_com = own_itoa(num_command);
    write(STDERR_FILENO,num_com, _strlen(num_com));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, commands[0], _strlen(commands[0]));
	write(STDERR_FILENO, ": not found\n", 12);

    free(num_com);
	free(buffer);
	free_commands(commands);
	exit(127);
}