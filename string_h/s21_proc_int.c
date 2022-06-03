#include "s21_sprintf.h"

size_t	proc_j(t_flags *flags, int i, long int *j, char* buf)
{
	size_t		len;

	len = 0;
	if (i < 0 && (flags->precision >= 0 || flags->zero == 1))
	{
		if (flags->zero == 1 && flags->precision < 0)
		{
			len += s21_putstr_prec("-", 1, buf);
			len--;
		}
		*(j) *= -1;
		flags->zero = 1;
		flags->width -= 1;
		len++;
	}
	return (len);
}

size_t	put_of_int_minus(t_flags *flags, char *str, int i, char* buf)
{
	size_t	len;

	len = 0;
	if (i < 0 && flags->precision >= 0)
		s21_strcat(buf, '-');
		//write(1, "-", 1);
	if (flags->precision >= 0)
		len += s21_add_width(flags->precision - 1, s21_strlen(str) - 1, 1, buf);
	len += s21_putstr_prec(str, s21_strlen(str), buf);
	return (len);
}

size_t	put_of_int_prec(t_flags *flags, char *str, char* buf)
{
	size_t	len;

	len = 0;
	if (flags->precision >= 0)
	{
		flags->width -= flags->precision;
		len += s21_add_width(flags->width, 0, 0, buf);
	}
	else
		len += s21_add_width(flags->width, s21_strlen(str), flags->zero, buf);
	return (len);
}

size_t	s21_proc_int(t_flags *flags, long int i, char* buf)
{
	char		*str;
	size_t		len;
	long int	j;

	len = 0;
	if (flags->sh == 1) 
		j = (short int)i;
	else
		if (flags->l == 0)
			j = (int)i;
		else
			j = i;
	if (flags->precision == 0 && i == 0)
		len += s21_add_width(flags->width, 0, 0, buf);
	else
	{
		len += proc_j(flags, i, &j, buf);
		str = s21_itoa(j);
		if (flags->minus == 1)
			len += put_of_int_minus(flags, str, i, buf);
		if (flags->precision >= 0 && flags->precision < (int)(s21_strlen(str)))
			flags->precision = s21_strlen(str);
		len += put_of_int_prec(flags, str, buf);
		if (flags->minus == 0)
			len += put_of_int_minus(flags, str, i, buf);
		free(str);
	}
	return (len);
}
