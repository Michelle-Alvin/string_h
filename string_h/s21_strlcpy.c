#include "s21_sprintf.h"

size_t	s21_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (src == NULL && dst == NULL)
		return (0);
	if (dstsize > 0)
	{	
		while (src[i] && i < (dstsize - 1))
		{	
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (s21_strlen(src));
}


