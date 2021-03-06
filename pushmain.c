#include "pushswap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (255);
}

int	ft_size(char *nmb)
{
	if (ft_strlen(nmb) > 11 || ft_atoi(nmb) > INT_MAX
		|| ft_atoi(nmb) < INT_MIN)
		return (1);
	return (0);
}

int	ft_checkrep(char **av, char *cmp, int max)
{
	int	i;

	i = -1;
	while (++i < max)
		if (!ft_strcmp(av[i], cmp))
			return (1);
	return (0);
}

int	ft_checkint(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' && !av[i][j + 1])
			return (1);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && (j != 0 || av[i][j] != '-'))
				return (1);
			j++;
		}
		if (ft_size(av[i]))
			return (1);
		if (ft_checkrep(av, av[i], i))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ft_checkint(av))
		ft_error();
	if (ac < 2)
		return (0);
	if (ac == 2)
		return (0);
	ft_startwork(av);
	return (0);
}
