#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	nb = n;
	i = ft_nbrcount(nb);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (nb < 0)
	{
		nb = nb * -1;
		str[0] = '-';
	}
	while (nb >= 10)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	if (nb >= 0 && nb < 10)
		str[i] = nb + '0';
	return (str);
}
