#include <unistd.h>

/**
 * _write - easier way just passing value to print
 *
 * @c: The character to print
 *
 * Return: 1 for the counter
 */
int _write(char c)
{
	return (write(1, &c, 1));
}
