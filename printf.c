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
	printf("%d", q);
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
write(STDOUT_FILENO, w, sizeof(char) * 6);
return (6);
}
