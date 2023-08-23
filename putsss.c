#include "main.h"
/*
 * putsss - prints string
 * @c: string
 * return: number of bytes
 */
int putsss(char *c)
{
	int count = 0;

	if (c)
	{
		for (count = 0; c[count] != '\0'; count++)
		{
			chars(c[count]);
		}
	}
	return (count);
}
