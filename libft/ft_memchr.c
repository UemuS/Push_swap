#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			l;

	l = 0;
	while (l < n)
	{
		if (((unsigned char *)s)[l] == (unsigned char)c)
			return ((unsigned char *)s + l);
		l++;
	}
	return (NULL);
}
