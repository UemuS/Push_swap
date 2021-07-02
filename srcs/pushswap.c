#include "pushswap.h"

t_stack	*ft_mallocatoi(char *str)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->el = (int)ft_atoi(str);
	return (a);
}

t_stack	*ft_filla(char **av)
{
	t_stack	*next;
	t_stack	*prev;
	int		i;

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

int	ft_count(t_stack *stack)
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

void	gosort(t_stacks *stacks)
{
	if (stacks->size <= 5)
	{
		if (stacks->size == 2)
			write(1, "ra\n", 3);
		else if (stacks->size == 3)
			threesort(stacks);
		else if (stacks->size > 3)
			fivesort(stacks);
	}
	else
		bigsort(stacks);
}

void	ft_startwork(char **av)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->sorted = NULL;
	stacks->mya = ft_filla(av);
	stacks->size = ft_count(stacks->mya);
	stacks->srt = malloc(sizeof(int) * stacks->size);
	while (stacks->mya->prev)
		stacks->mya = stacks->mya->prev;
	if (!issorted(stacks->mya))
		gosort(stacks);
	freethestack(stacks);
}
