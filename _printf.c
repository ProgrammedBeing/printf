#include "main.h"
/**
 * print_char - Function for printing characters
 * @ctx: Pointer
 * @c: Character
 *
 * Return: 1
 */
int print_char(PrintfContext *ctx, char c)
{
	_putchar(c);
	ctx->count++;
	return (1);
}

/**
 * print_string - Print strings
 *
 * @ctx: Struct pointer
 * @str: String.
 *
 * Return: Count
 */
int print_string(PrintfContext *ctx, const char *str)
{
	int len = 0;
	const char *s;

	for (s = str; *s; s++)
	{
		_putchar(*s);
		len++;
	}
	ctx->count += len;
	return (len);
}

/**
 * print_percent - Function for printing %
 * @ctx: Structure pointer
 *
 * Return: Return 1
 */

int print_percent(PrintfContext *ctx)
{
	_putchar('%');
	ctx->count++;
	return (1);
}

/**
 * print_format - main print format function
 * @ctx: Pointer to a structure.
 *
 * Return: count
 */
int print_format(PrintfContext *ctx)
{
	while (*(ctx->format))
	{
		if (*(ctx->format) == '%')
		{
			ctx->format++;
			switch (*(ctx->format))
			{
				case 'c':
					print_char(ctx, va_arg(ctx->args, int));
					break;
				case 's':
					print_string(ctx, va_arg(ctx->args, const char *));
					break;
				case '%':
					print_percent(ctx);
					break;
				default:
					print_percent(ctx);
					print_char(ctx, *(ctx->format));
					break;
			}
		}
		else
			print_char(ctx, *(ctx->format));
		ctx->format++;
	}
	return (ctx->count);
}

/**
 * _printf - Similar too printf function
 * @format: a variable
 *
 * Return: length.
 */
int _printf(const char *format, ...)
{
	int result;

	PrintfContext ctx;

	ctx.format = format;
	va_start(ctx.args, format);
	ctx.count = 0;

	result = print_format(&ctx);

	va_end(ctx.args);

	return (result);
}
