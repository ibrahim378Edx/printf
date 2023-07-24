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
va_list args;
int q;
q = 0;
va_start(args, z);
if (z == NULL)
	return (-1);

while (z != NULL)
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
			write(STDOUT_FILENO, z, 1);
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
va_end(args);
return (q);
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
 * specifierS - Specifier for %s
 *
 * @str: string to print
 *
 * @q: counter of chars printed
 *
 * Return: returing q again after updating
*/
int specifierS(char *str, int q)
{
char *w = "(null)";
if (str != NULL)
{
while (*str != '\0')
{
	write(STDOUT_FILENO, str, sizeof(char));
	str++;
	q++;
}
return (q);
}
else
{
write(STDOUT_FILENO, w, sizeof(char) * 6);
return (q + 6);
}
}
