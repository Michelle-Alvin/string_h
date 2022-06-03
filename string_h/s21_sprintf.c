#include "s21_sprintf.h"
#include <stdio.h>


void	s21_init_flags(t_flags *flags)
{
	flags->type = 0;
	flags->width = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = -1;
	flags->star = 0;
	flags->sh=0;
	flags->l=0;
}

size_t	put_char(char c, char *buf)
{
	size_t	len;
	len = 0;
	
	s21_strcat(buf, c);
	//write(1, &c, 1);
	len++;
	return (len);
}

size_t	s21_parse_input(const char *format, va_list arg, char* buf)
{
	t_flags	flags;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (1)
	{
		if (format[i] == '\0')
			break;
		else if (format[i] == '%')
		{
			s21_init_flags(&flags);
			if (format[i + 1] == ' ')
				len += put_char(' ', buf);
			i = s21_parse_flag(format, i, &flags, arg, buf);
			if (s21_is_type(format[i]))
				len += s21_processor(format[i], &flags, arg, buf);
		}
		else
			len += put_char(format[i], buf);
		i++;
	}
	return (len);
}

int	s21_sprintf(char *buf, const char *format, ...)
{
	size_t	len;
	va_list	arg;
	va_start(arg, format);
	len = 0;
	len += s21_parse_input(format, arg, buf);

	va_end(arg);
	return (len);
}

int main() {
	//char c[100];
	//int b = 70;
	char buf[1000];
	s21_sprintf(buf, "%f% d% s", 12.675, 123, "qwe");
	printf("%s", buf);
}