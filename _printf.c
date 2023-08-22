#include "main.h"
/**
 * print_char - prints a single character
 * @c: the character to be printed
 * @char_print: pointer to the counter for printed characters
 */
void print_char(char c, int *char_print)
{
	write(1, &c, 1);
	(*char_print)++;
}

/**
 * print_string - Prints a string and updates char_print counter
 * @str: The string to be printed
 * @char_print: Pointer to the counter for printed characters
 */
void print_string(char *str, int *char_print)
{
	int len_str = 0;

	while (str[len_str] != '\0')
		len_str++;
	write(1, str, len_str);
	(*char_print) += len_str;
}

/**
 * _printf - our version of printf to print data of all formats
 * @format: Input string
 * @...: Variadic arguments
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
	{
		return (-1);
	}
	int char_print = 0;
	va_list list_args;

	va_start(list_args, format);
	while (*format)
		if (*format != '%')
			print_char(*format, &char_print);
		else
			format++;
			if (*format == '\0')
				return (1);
			if (*format == ' ')
				if ((*format + 1) == '\0')
					return (-1);
			if (*format == '%')
				print_char('%', &char_print);
			else if (*format == 'c')
				char c = va_arg(list_args, int);

				print_char(c, &char_print);
			else if (*format == 's')
				char *str = va_arg(list_args, char*);

				if (str == NULL)
					str = "(null)";
				print_string(str, &char_print);
		format++;
	va_end(list_args);
	return (char_print);
}
