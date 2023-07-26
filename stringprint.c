#include "main.h"

/**
  * stringprint - prints the rest of the string
  *
  * @format: the actually string without directives
  *
  * @args: valist return
  *
  * Return: length of the printed string
  */
int stringprint(const char *format, va_list args)
{
int count = 0;
int i = 0;
while (format && format[i])
{
	if (format[i] == '%')
	{
		if (format[i + 1] == '\0')
			return (-1);

		i++;

		while (format[i] == ' ')
			i++;

		if (format[i] == '%')
			count += _write(format[i]);

		if (specheck(format[i]) == 0)
		{
			count = badspec(format[i - 1], format[i], count);
		}
		else
		{
			count += specifierchecker(format[i], args);
		}
	}
	else
	{
		count += _write(format[i]);
	}
	i++;
}

	return (count);
}

/**
  * specifierchecker - specifier check
  *
  * @format: the returned char after %
  *
  * @args: valist return
  *
  * Return: printed values of the specifier
  */
int specifierchecker(char format, va_list args)
{
	int i  = 0, length = 0;
	spc_dt _types[] = {
		{"c", specifierC},
		{"s", specifierS},
		{"d", specifierDI},
		{"i", specifierDI},
		{"b", binarycalc},
		{NULL, NULL}
	};

	while (_types[i].specifier)
	{
		if (*_types[i].specifier == format)
			length = _types[i].f(args);

		i++;
	}

	return (length);
}

/**
  * badspec - checks for non supported or incorrect spec
  *
  * @prevformat: The previous specifier of actual specifier
  *
  * @format: The specifier to prints
  *
  * @count: The current count before prints invalid specifiers
  *
  * Return: count
  */
int badspec(char prevformat, char format, int count)
{
count += _write('%');
if (prevformat == ' ')
{
	count += _write(' ');
	count += _write(format);
}
else
{
	count += _write(format);
}
return (count);
}

/**
  * specheck - checks the specifier
  *
  * @type: char to check
  *
  * Return: if specifier found return 1
  */
int specheck(char type)
{
char _types[] = {'c', 's', 'd', 'i', 'b', '%'};
int i = 0;
while (_types[i])
{
	if (_types[i] == type)
	return (1);
	i++;
}
return (0);
}
