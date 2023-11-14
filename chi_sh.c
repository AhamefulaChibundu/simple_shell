#include "main.h"

/**
 * main - main file for my shell
 * Return: 0
 */

int main(void)
{
	char *buffer = NULL, *prompt = "(chi_sh)$ ", *str_token, *str_array[1024];
	size_t size_of_buffer = 0;
	ssize_t line_args;
	int m = 0, hold_on;
	const char *delimiter = " \n";
	pid_t my_child_process;

	while (1)
	{
		if (isatty(STDOUT_FILENO) && isatty(STDIN_FILENO))
			_print_str(prompt);
		line_args = getline(&buffer, &size_of_buffer, stdin);
		if (line_args == -1)
		{
			perror("Error reading input");
			break;
		}
		m = 0; /*This reesets the index for str_array for each iteration*/
		str_token = strtok(buffer, delimiter);
		while (str_token)
		{
			str_array[m] = str_token;
			m++;
			str_token = strtok(NULL, delimiter);
		}
		str_array[m] = NULL;
		my_child_process = fork();
		if (my_child_process == -1)
		{
			perror("Fork failed");
			break;
		}
		if (my_child_process == 0)
		{
			if (execvp(str_array[0], str_array) == -1)
			{
				perror("Execution failed");
				free(buffer);
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&hold_on);
	}
	free(buffer);
	return (0);
}
