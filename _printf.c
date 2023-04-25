#include "main.h"
#include <stdio.h>
/**
 * _printf_helper - function that produces output according to a format
 * @format: character string - composed of zero or more directives.
 * @arg: character string - composed of zero or more directives.
 * @i: character string - composed of zero or more directives.
 * Return:  the number of characters printed without null
 */
int _printf_helper(const char *format, va_list arg, int *i)
{
	int res = 0, j;
	char *tmp;

	switch (*(format + *i + 1))
	{
	case 's':
		tmp = va_arg(arg, char *);
		for (j = 0; tmp[j] != '\0'; j++)
		{
			_putchar(tmp[j]);
			res++;
		}
		*i += 1;
		break;
	case 'c':
		_putchar(va_arg(arg, int));
		res++;
		*i += 1;
		break;
	case '%':
		_putchar(format[*i]);
		res++;
		*i += 1;
		break;
	default:
		_putchar(format[*i]);
		res++;
		break;
	}
	return (res);
}
/**
 * _printf - function that produces output according to a format
 * @format: character string - composed of zero or more directives.
 * Return:  the number of characters printed without null
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);
	for (i = 0; *(format + i) != '\0'; i++)
	{
		if (*(format + i) == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			count += _printf_helper(format, arg, &i);
		}
		else
		{
			_putchar(*(format + i));
			count++;
		}
	}
	va_end(arg);
	return (count);
}
