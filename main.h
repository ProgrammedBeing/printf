#ifndef MAIN_H_
#define MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
typedef struct
{
	const char *format;
	va_list args;
	int count;
} PrintfContext;
int _putchar(char c);
int _printf(const char *format, ...);

#endif
