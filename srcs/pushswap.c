#include "pushswap.h"

t_stacka	*ft_mallocatoi(char *str)
{
	t_stacka	*a;

	a = malloc(sizeof(t_stacka));
	if (!a)
		return (NULL);
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
		if (!next)
			return (NULL);
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

int	ft_count(t_stacka *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	ft_startwork(char **av)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->mystack = ft_filla(av);
	stacks->size = ft_count(stacks->mystack);
}
