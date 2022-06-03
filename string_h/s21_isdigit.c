#include "s21_sprintf.h"

int	s21_isdigit(int c)
{
    int a = 0;
	if (c >= '0' && c <= '9')
		a = 1;
	else
		a = 0;
    return a;
}
