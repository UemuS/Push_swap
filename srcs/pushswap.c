#include "pushswap.h"

t_stacka	*ft_mallocatoi(char *str)
{
	t_stacka	*a;

	a = malloc(sizeof(t_stacka));
	a->elem_a = (int)ft_atoi(str);
	return (a);
}

t_stacka	*ft_filla(char **av)
{
	t_stacka	*next;
	t_stacka	*prev;
	int			i;

	i = 1;
	next = NULL;
	prev = NULL;
	while (av[i])
	{
		next = ft_mallocatoi(av[i]);
		next->prev = prev;
		if (prev)
			prev->next = next;
		prev = next;
		i++;
	}
	if (next)
		next->next = NULL;
	while (next && next->prev)
		next = next->prev;
	return (next);
}

void	ft_pushswap(t_stacks *stacks)
{
	
}

void	ft_startwork(char **av)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->mystack = ft_filla(av);
	ft_pushswap(stacks);
}
