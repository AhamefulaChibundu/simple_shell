#include <unistd.h>
#include "main.h"
/**
 * _print_str - prints string to stdout
 *
 * @str: The string to print using _print_str
 *
 * Return: 0
 */

int _print_str(char *str)

{
	int m;
	
	for (m = 0; str[m] != '\0'; m++)
	{
		_putchar(str[m]);
	}

}
