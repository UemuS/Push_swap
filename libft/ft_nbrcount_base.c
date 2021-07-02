#include "libft.h"

size_t	ft_nbrcount_base(unsigned long long n, size_t base)
{
	size_t	c;

	c = 0;
	if (n < base)
		return (c + 1);
	else
	{
		while (n >= base)
		{
			c += ft_nbrcount_base(n % base, base);
			n = n / base;
		}
	}
	return (++c);
}
