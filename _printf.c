#include "main.h"

/**
 * _printf: our version of printf to print data of all formats
 * @format: input string
 * @c: character wanting to print
 * string: used to print strings
 * @char_print: used to print characters
 * @print_string: used to print strings
 *
 * return: number of characters returned
 */

void print_char(char c, int *char_print)
{
	write(1, &c, 1);
	(*char_print)++;
}

void print_string(char *str, int *char_print)
{
	int len_str = 0;

	while (str[len_str] != '\0')
		len_str++;
	write(1, str, len_str);
	(*char_print) += len_str;
}

int _printf(const char *format, ...)
{
	int char_print = 0;
	va_list list_args;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list_args, format);
	while (*format)
	{
		if (*format != '%')
		{
			print_char(*format, &char_print);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				print_char(*format, &char_print);
			}
			else if (*format == 'c')
			{
				char c = va_arg(list_args, int);

				print_char(c, &char_print);
			}
			else if (*format == 's')
			{
				char *str = va_arg(list_args, char*);

				print_string(str, &char_print);
			}
		}
		format++;
	}
	va_end(list_args);
	return (char_print);
}
