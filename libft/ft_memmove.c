#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	l;

	l = 0;
	if (dst < src)
	{
		while (l < len)
		{
			((unsigned char *)dst)[l] = ((unsigned char *)src)[l];
			l++;
		}
	}
	else if (dst > src)
	{
		len--;
		while (len + 1 > 0)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
			len--;
		}
	}
	return (dst);
}
