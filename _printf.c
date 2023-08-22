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
                char str = va_arg(list_args, char);
                print_string(str, &char_print);
            }
            else if (*format == 'd' || *format == 'i') // Handle %d and %i specifier
            {
                int num = va_arg(list_args, int);
                if (num < 0)
                {
                    print_char('-', &char_print);
                    num = -num;
                }
                char num_str[20];
                int len = 0;
                while (num > 0)
                {
                    num_str[len] = (num % 10) + '0';
                    num /= 10;
                    len++;
                }
                if (len == 0)
                {
                    num_str[len] = '0';
                    len++;
                }
                for (int i = len - 1; i >= 0; i--)
                {
                    print_char(num_str[i], &char_print);
                }
            }
            else if (*format == 'u') // Handle %u specifier
            {
                unsigned int num = va_arg(list_args, unsigned int);
                char num_str[20];
                int len = 0;
                while (num > 0)
                {
                    num_str[len] = (num % 10) + '0';
                    num /= 10;
                    len++;
                }
                if (len == 0)
                {
                    num_str[len] = '0';
                    len++;
                }
                for (int i = len - 1; i >= 0; i--)
                {
                    print_char(num_str[i], &char_print);
                }
            }
            else if (*format == 'o') // Handle %o specifier
            {
                unsigned int num = va_arg(list_args, unsigned int);
                char num_str[20];
                int len = 0;
                while (num > 0)
                {
                    num_str[len] = (num % 8) + '0';
                    num /= 8;
                    len++;
                }
                if (len == 0)
                {
                    num_str[len] = '0';
                    len++;
                }
                for (int i = len - 1; i >= 0; i--)
                {
                    print_char(num_str[i], &char_print);
                }
            }
            else if (*format == 'x' || *format == 'X') // Handle %x and %X specifier
            {
                unsigned int num = va_arg(list_args, unsigned int);
                char num_str[20];
                int len = 0;
                while (num > 0)
                {
                    int digit = num % 16;
                    if (digit < 10)
                        num_str[len] = digit + '0';
                    else
                        num_str[len] = (digit - 10) + ((*format == 'x') ? 'a' : 'A');
                    num /= 16;
                    len++;
                }
                if (len == 0)
                {
                    num_str[len] = '0';
                    len++;
                }
                for (int i = len - 1; i >= 0; i--)
                {
                    print_char(num_str[i], &char_print);
                }
            }
        }
        format++;
    }
    va_end(list_args);
    return char_print;
}
