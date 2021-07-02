#include "pushswap.h"

int	ft_pow(int x, unsigned int y)
{
	int	temp;

	if (y == 0)
		return (1);
	temp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
		return (x * temp * temp);
}

int	ft_index(int *srt, int el, int max)
{
	int	i;

	i = 0;
	while(i < max)
	{
		if (srt[i] == el)
			return (i);
		i++;
	}
	return (i);
}

int	ft_nextbase(int max)
{
	int	i;

	i = 0;
	while(ft_pow(2, i) < max)
		i++;
	return (i);
}

int	ft_getlast(t_stack *stack)
{
	while (stack)
	{
		if (stack->next)
			stack = stack->next;
		else
			break;
	}
	return (stack->el);
}

void	ft_radix(t_stacks *stacks)
{
	int	i;
	int	bits;
	int	last;

	i = 0;
	bits = ft_nextbase(stacks->size);
	while (i < bits && !issorted(stacks->mya))
	{
		last = ft_getlast(stacks->mya);
		while(stacks->mya->el != last)
		{
			if (stacks->mya->el & ft_pow(2, i))
				ft_execwrite("ra", stacks);
			else
				ft_execwrite("pb", stacks);
		}
		if (stacks->mya->el & ft_pow(2, i))
			ft_execwrite("ra", stacks);
		else
			ft_execwrite("pb", stacks);
		while (stacks->sorted)
		{
			ft_execwrite("pa", stacks);
		}
		i++;
	}
}
