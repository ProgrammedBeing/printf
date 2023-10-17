#include "main.h"

int _printf(const char *format, ...)
{
	char *str;
	unsigned int count = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++; /* Move past the '%' */
			switch(*format)
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					{
						str = va_arg(args, char *);
						while (*str)
						{
							_putchar(*str);
							str++;
							count++;
						}
					}
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}
