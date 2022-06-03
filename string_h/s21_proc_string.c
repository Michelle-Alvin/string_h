#include "s21_sprintf.h"

size_t	proc_flag_minus(t_flags *flags, char *str, char* buf)
{
	size_t	len;

	len = 0;
	if (flags->precision >= 0)
	{
		len += s21_add_width(flags->precision, s21_strlen(str), flags->zero, buf);
		len += s21_putstr_prec(str, flags->precision, buf);
	}
	else
		len += s21_putstr_prec(str, s21_strlen(str), buf);
	return (len);
}

size_t	s21_proc_string(t_flags *flags, char *str, char* buf)
{
	size_t	len;

	len = 0;
	if (!str)
		str = "(null)";
	if (flags->precision >= 0 && flags->precision > (int)s21_strlen(str))
		flags->precision = (int)s21_strlen(str);
	if (flags->minus == 1)
		len += proc_flag_minus(flags, str, buf);
	if (flags->precision >= 0)
		len += s21_add_width(flags->width, flags->precision, flags->zero, buf);
	else
		len += s21_add_width(flags->width, s21_strlen(str), flags->zero, buf);
	if (flags->minus == 0)
		len += proc_flag_minus(flags, str, buf);
	return (len);
}
