#include "main.h"
/*
 * chars - prints a character
 * @c: char input
 * return: 1
 */
int chars(char c)
{
	return (write(1, &c, 1));
}
