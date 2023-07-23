#include "main.h"
#include <unistd.h>
/**
 * _printf -  trying to replicate printf
 *
 * @z: string provided by user
 *
 * Return: amount of chars printed
 */
int  _printf(const char *z, ...)
{
if(z == NULL)
{
return (NULL);
}
va_list args;
int q;
q = 0;
va_start(args, z);
	while (*z != '\0')
	{
		if (*z == '%')
		{
			z++;
			if (*z == 'c')
			{
				char c = (char) va_arg(args, int);

				q = specifierC(c, q);
				z++;
			}
			else if (*z == 's')
			{
				char *str = va_arg(args, char*);

				q = specifierS(str, q);
				z++;
			}
			else if (*z == '%')
			{
				char percent;

				percent = '%';
				write(STDOUT_FILENO, &percent, 1);
				q++;
				z++;
			}

		}
		else
		{
			write(STDOUT_FILENO, z, sizeof(char));
			q++;
			z++;
		}
	}
return (q);
}

/**
 * counter - counter for the full string
 *
 * @z: string provided by user
 *
 * Return: the string length
 */
int counter(const char *z)
{
int i;
i = 0;
	while (*(z + i) != '\0')
	{
	i++;
	}
return (i);
}
/**
 * specifierC - Specifier for %s
 *
 * @c: char to print
 *
 * @q: counter of chars printed
 *
 * Return: returing q again after updating
*/
int specifierC(char c, int q)
{
write(STDOUT_FILENO, &c, sizeof(char));
q++;
return (q);
}
/**
 * specifierS - Specifier for %c
 *
 * @str: string to print
 *
 * @q: counter of chars printed
 *
 * Return: returing q again after updating
*/
int specifierS(char *str, int q)
{
while (*str != '\0')
{
	write(STDOUT_FILENO, str, sizeof(char));
	str++;
	q++;
}
return (q);
}
