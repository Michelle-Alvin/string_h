#include "s21_sprintf.h"

char	*s21_strdup(const char *s1)
{
	char	*ptr;
	size_t	n;

	n = s21_strlen(s1);
	ptr = (char *)malloc(n + 1);
	if (!ptr)
		return (NULL);
	s21_strlcpy(ptr, s1, n + 1);
	return (ptr);
}
