#include "main.h"_printf - printf function

/**
 * handle_print - prints an argument based on its type
 * @fmt: formated string in which to print the argument
 * @ind: ind
 * @buffer: buffer
 * @flags: flag
 * @width: widht
 * @precision: precised specification
 * @size: Size specificstion
 * Return: 1 or 2;
 */

int handle_print(const char *fmt, int *ind, va_list list char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', printed_char}, {'s', printed_string}, {'%', printed_percent},
		{'i', printed_int}, {'d', printed_int}, {'b', printed_binary},
		{'u', printed_unsigned}, {'o', printed_octal}, {'x', printed_hexadecimal},
		{'X', printed_hexda_upper}, {'p', printed_pointer},
		{'S', print_non_printable}, {'r', printed_reverse}, {'R', print_rot13string},
		{'\0', NULL}
	}
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unnow_len);
	}
	return (printed_chars);
}
