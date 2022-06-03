#include "s21_sprintf.h"

size_t	s21_parse_flag(const char *format, size_t i, t_flags *flags, va_list arg, char* buf)
{
	i++;
	while (format[i])
	{
		if (format[i] == '0' && !(flags->width) && !(flags->minus))
			flags->zero = 1;
		if (format[i] == '.')
			s21_flag_dot(format, &i, flags, arg);
		if (format[i] == '-')
			s21_flag_minus(flags);
		if (format[i] == '+')
			put_char('+', buf);
		if (format[i] == '*')
			s21_flag_width(flags, arg);
		if (format[i] == 'h')
			flags->sh = 1;
		if (format[i] == 'l')
			flags->l = 1;
		if (s21_isdigit(format[i]))
			s21_flag_digit(format[i], flags);
		if (s21_is_type(format[i]))
		{
			flags->type = format[i];
			break ;
		}
		i++;
	}
	return (i);
}