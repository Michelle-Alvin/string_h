#include "s21_sprintf.h"

size_t	len_str_p(unsigned long p)
{
	unsigned long	tmp;
	size_t			i;

	i = 0;
	tmp = p;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		i++;
	}
	return (i);
}

char	*str_pointer(unsigned long p)
{
	size_t	i;
	char	*str;

	i = len_str_p(p);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	while (p != 0)
	{
		if (p % 16 < 10)
			str[i] = p % 16 + 48;
		else
			str[i] = p % 16 + 87;
		p /= 16;
		i--;
	}
	return (str);
}

size_t	put_result(t_flags *flags, char *str, char* buf)
{
	size_t	len;

	len = 0;
	if (flags->minus == 1)
	{
		len += s21_putstr_prec("0x", 2, buf);
		len += s21_putstr_prec(str, s21_strlen(str), buf);
		len += s21_add_width(flags->width - 2, s21_strlen(str), flags->zero, buf);
	}
	else
	{
		len += s21_add_width(flags->width - 2, s21_strlen(str), flags->zero, buf);
		len += s21_putstr_prec("0x", 2, buf);
		len += s21_putstr_prec(str, s21_strlen(str), buf);
	}
	return (len);
}

size_t	put_point_zero(t_flags *flags, char* buf)
{
	size_t	len;

	len = 0;
	if (flags->minus)
	{
		len += s21_putstr_prec("0x", 2, buf);
		len += s21_add_width(flags->width - 2, flags->precision, 0, buf);
	}
	else
	{
		len += s21_add_width(flags->width - 2, flags->precision, 0, buf);
		len += s21_putstr_prec("0x", 2, buf);
	}
	return (len);
}

size_t	s21_proc_pointer(t_flags *flags, unsigned long p, char* buf)
{
	char			*str;
	size_t			len;

	if (p == 0 && flags->precision == 0)
		len = put_point_zero(flags, buf);
	else
	{
		if (p == 0)
			str = s21_strdup("0");
		else
			str = str_pointer(p);
		len = put_result(flags, str, buf);
		free(str);
	}
	return (len);
}
