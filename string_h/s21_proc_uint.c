#include "s21_sprintf.h"

int	len_str_u(unsigned int n)
{
	unsigned int	tmp;
	int				len;

	tmp = n;
	len = 0;
	while (tmp > 0)
	{
		len++;
		tmp /= 10;
	}
	return (len);
}

char	*s21_uitoa(unsigned int n)
{
	char			*str;
	int				len;

	if (n == 0)
	{
		str = s21_strdup("0");
		return (str);
	}
	len = len_str_u(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (n > 0)
	{
		str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}

size_t	put_of_uint_minus(t_flags *flags, char *str, char* buf)
{
	size_t	len;

	len = 0;
	if (flags->precision >= 0)
		len += s21_add_width(flags->precision - 1, s21_strlen(str) - 1, 1, buf);
	len += s21_putstr_prec(str, s21_strlen(str), buf);
	return (len);
}

size_t	put_of_uint_prec(t_flags *flags, char* buf)
{
	size_t	len;

	len = 0;
	flags->width -= flags->precision;
	len += s21_add_width(flags->width, 0, 0, buf);
	return (len);
}

size_t	s21_proc_uint(t_flags *flags, unsigned int i, char* buf)
{
	char	*str;
	size_t	len;

	len = 0;
	i += 4294967295 + 1;
	if (flags->precision == 0 && i == 0)
	{
		len += s21_add_width(flags->width, 0, 0, buf);
		return (len);
	}
	str = s21_uitoa(i);
	if (flags->minus == 1)
		len += put_of_uint_minus(flags, str, buf);
	if (flags->precision >= 0 && flags->precision < (int)(s21_strlen(str)))
		flags->precision = s21_strlen(str);
	if (flags->precision >= 0)
		len += put_of_uint_prec(flags, buf);
	else
		len += s21_add_width(flags->width, s21_strlen(str), flags->zero, buf);
	if (flags->minus == 0)
		len += put_of_uint_minus(flags, str, buf);
	free(str);
	return (len);
}
