#include "s21_sprintf.h"

void	s21_flag_dot(const char *format, size_t *i, t_flags *flags, va_list arg)
{
	(*i)++;
	if (format[*i] == '*')
	{
		flags->precision = va_arg(arg, int);
		(*i)++;
	}
	else
	{
		flags->precision = 0;
		while (s21_isdigit(format[*i]))
		{
			flags->precision = flags->precision * 10 + format[*i] - '0';
			(*i)++;
		}
	}
}

void	s21_flag_width(t_flags *flags, va_list arg)
{
	flags->star = 1;
	flags->width = va_arg(arg, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= (-1);
		flags->zero = 0;
	}
}

void	s21_flag_minus(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
}

void	s21_flag_digit(char c, t_flags *flags)
{
	if (flags->star == 1)
		flags->width = 0;
	else
		flags->width = flags->width * 10 + (c - '0');
}

int	s21_is_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%') || (c == 'f'));
}

