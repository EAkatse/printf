#include "main.h"
/*
 * _printf - prints to stout
 * @format: format specifier
 * return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	unsigned int i, string_count, count = 0;

	va_list list_args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
	return (-1);

	va_start(list_args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			chars(format[i]);
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			chars(va_arg(list_args, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			string_count = putsss(va_arg(list_args, char *));
			i++;
			count += (string_count - 1);
		}
		else if (format[i + 1] == '%')
		{
			chars('%');
		}
		count += 1;
	}
	va_end(list_args);
	return (count);
}
