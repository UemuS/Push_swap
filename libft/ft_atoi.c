#include "libft.h"
#include <stdio.h>
#include <errno.h>

void	ft_overflow_setter(int sign, long *res)
{
	if (sign == -1)
	{
		errno = 34;
		*res = 0;
	}
	else if (sign == 1)
	{
		errno = 22;
		*res = -1;
	}
}

long	ft_atoi(const char *str)
{
	size_t	l;
	long	res;
	int		sign;

	l = 0;
	res = 0;
	sign = 1;
	while (str[l] != '\0' && ((str[l] >= 9 && str[l] <= 13) || str[l] == 32))
		l++;
	if (str[l] == '-')
		sign = -1;
	if (str[l] == '-' || str[l] == '+')
		l++;
	while (str[l] != '\0' && str[l] >= 48 && str[l] <= 57)
	{
		if (res * 10 + str[l] - '0' < res)
		{
			ft_overflow_setter(sign, &res);
			break ;
		}
		res = res * 10 + str[l++] - '0';
	}
	return (res * sign);
}
