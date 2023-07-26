#include "main.h"
/**
  * binarycalc - calculate the binary value
  * 
  * @args: values to print
  *
  * Return: The number of printed digits
  */
int binarycalc(va_list args)
{
unsigned int x = 0;
int b = 0, new = 0;

new = va_arg(args, int);
x = new;
if (new < 0)
{
	_write('1');
	new = new * -1;
	x = new;
	b += 1;
}
while (x > 0)
{
	x = x / 2;
	b++;
}
binaryrec(new);
return (b);
}

/**
  * binaryrec - Prints a binary
  * 
  * @a: integer to print
  *
  * Return: nothing
  */
void binaryrec(int a)
{
unsigned int t;
t = a;
if (t / 2)
{
	binaryrec(t / 2);
}
_write(t % 2 + '0');
}
