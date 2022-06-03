#include "s21_sprintf.h"

size_t	s21_proc_percent(t_flags *flags, char* buf)
{
	size_t	len;

	len = 0;
	if (flags->minus == 1)
		len += s21_putstr_prec("%", 1, buf);
	len += s21_add_width(flags->width, 1, flags->zero, buf);
	if (flags->minus == 0)
		len += s21_putstr_prec("%", 1, buf);
	return (len);
}
