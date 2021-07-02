#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		l;

	l = 0;
	if (src != dst)
	{
		while (l < n)
		{
			((unsigned char *)dst)[l] = ((unsigned char *)src)[l];
			l++;
		}
	}
	return (dst);
}
