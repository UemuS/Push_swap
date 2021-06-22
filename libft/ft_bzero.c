#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	l;

	l = 0;
	while (l < n)
		((unsigned char *)s)[l++] = '\0';
}
