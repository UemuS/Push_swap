#include "pushswap.h"

int	ft_ismin(t_stack *stack, int size)
{
	int	i;
	int	min;

	i = 0;
	min = stack->el;
	while (stack)
	{
		if (stack->el < min)
			min = stack->el;
		if (stack->next)
			stack = stack->next;
		else
			break ;
	}
	while (stack && stack->prev)
		stack = stack->prev;
	while (stack && stack->el != min)
	{
		stack = stack->next;
		i++;
	}
	return ((i != 0) + (i > size / 2));
}

void	bigsort(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->mya)
	{
		stacks->srt[i++] = stacks->mya->el;
		if (stacks->mya->next)
			stacks->mya = stacks->mya->next;
		else
			break ;
	}
	while (stacks->mya->prev)
		stacks->mya = stacks->mya->prev;
	selectionsort(stacks->srt, stacks->size);
	while (stacks->mya)
	{
		stacks->mya->el = ft_index(stacks->srt, stacks->mya->el, stacks->size);
		if (stacks->mya->next)
			stacks->mya = stacks->mya->next;
		else
			break ;
	}
	while (stacks->mya->prev)
		stacks->mya = stacks->mya->prev;
	ft_radix(stacks);
}

void	fivesort(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->size - i > 3)
	{
		if (ft_ismin(stacks->mya, stacks->size - i) == 1)
			ft_execwrite("ra", stacks);
		else if (ft_ismin(stacks->mya, stacks->size - i) == 2)
			ft_execwrite("rra", stacks);
		else
		{
			ft_execwrite("pb", stacks);
			i++;
		}
	}
	if (stacks->sorted && stacks->sorted->next)
		if (stacks->sorted->el < stacks->sorted->next->el)
			ft_execwrite("rb", stacks);
	threesort(stacks);
	while (stacks->sorted)
		ft_execwrite("pa", stacks);
}

void	threesort(t_stacks *stacks)
{
	if (stacks->mya->el > stacks->mya->next->el
		&& !issorted(stacks->mya))
	{
		if (stacks->mya->next->el > stacks->mya->next->next->el)
		{
			ft_execwrite("sa", stacks);
			ft_execwrite("rra", stacks);
		}
		else if (stacks->mya->next->next->el > stacks->mya->el)
			ft_execwrite("sa", stacks);
		else
			ft_execwrite("ra", stacks);
	}
	else if (!issorted(stacks->mya))
	{
		if (stacks->mya->next->next->el > stacks->mya->el)
		{
			ft_execwrite("sa", stacks);
			ft_execwrite("ra", stacks);
		}
		else
			ft_execwrite("rra", stacks);
	}
}
