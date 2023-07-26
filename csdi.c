#include "main.h"

/**
  * specifierC - Prints a char
  *
  * @args: arg to print
  *
  * Return: return 1 for the printed charater
  */
int specifierC(va_list args)
{
_write(va_arg(args, int));
return (1);
}

/**
  * specifierS - Prints a string
  *
  * @args: args to print
  *
  * Return: length of the printed string
  */
int specifierS(va_list args)
{
char *arg = va_arg(args, char *);
int i = 0;
if (arg != NULL)
{
	while (arg[i])
	{
		_write(arg[i]);
		i++;
	}

	return (i);
}

_write('(');
_write('n');
_write('u');
_write('l');
_write('l');
_write(')');
return (6);
}

/**
  * specifierDI - counter and rec caller
  *
  * @args: args to print
  *
  * Return: lengths of the printed number
  */
int specifierDI(va_list args)
{
int count = 1, m = 0;
unsigned int n = 0;

n = va_arg(args, int);
m = n;
if (m < 0)
{
	_write('-');
	m = m * -1;
	n = m;
	count += 1;
}
while (n > 9)
{
	n = n / 10;
	count++;
}

intrec(m);
return (count);
}

/**
  * intrec - Prints a integer
  *
  * @a: integer to print
  *
  * Return: Nothing
  */
void intrec(int a)
{
unsigned int t;

t = a;
if (t / 10)
{
	intrec(t / 10);
}
_write(t % 10 + '0');
}
