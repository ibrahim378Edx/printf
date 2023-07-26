
#include "main.h"

/**
 * _printf - function my printf
 * @format: string whit format to print
 *
 * Return: number of chars that print
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;

if (format == NULL)
{
return (-1);
}
va_start(args, format);
i = stringprint(format, args);
va_end(args);
return (i);
}
