#include "s21_sprintf.h"

size_t	s21_proc_char(t_flags *flags, char c, char* buf)
{
	size_t	len;

	len = 0;
	if (flags->minus == 1)
		s21_strcat(buf, c);
		//write(1, &c, 1);
	len += s21_add_width(flags->width, 1, flags->zero, buf);
	if (flags->minus == 0)
		s21_strcat(buf, c);
		//write(1, &c, 1);
	len++;
	return (len);
}