#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	l;

	l = 0;
	while (l < len)
	{
		((unsigned char *)b)[l] = (unsigned char)c;
		l++;
	}
	return (b);
}
