#include "pushswap.h"

t_stack	*ft_mallocatoi(char *str)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->elem = (int)ft_atoi(str);
	return (a);
}

t_stack	*ft_filla(char **av)
{
	t_stack	*next;
	t_stack	*prev;
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

int	issorted(t_stack *stack)
{
	while(stack)
	{
		if (stack->prev && stack->elem < stack->prev->elem)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_execwrite(char *instruction, t_stacks *stacks)
{
	write(1, instruction, ft_strlen(instruction));
	write(1, "\n", 1);
	if (!ft_strcmp(instruction, "sa"))
		ft_swapa(stacks);
	if (!ft_strcmp(instruction, "sb"))
		ft_swapb(stacks);
	if (!ft_strcmp(instruction, "ss"))
		ft_swapa(stacks) && ft_swapb(stacks);
	if (!ft_strcmp(instruction, "ra"))
		ft_rotatea(stacks);
	if (!ft_strcmp(instruction, "rb"))
		ft_rotateb(stacks);
	if (!ft_strcmp(instruction, "rr"))
		ft_rotatea(stacks) && ft_rotateb(stacks);
	if (!ft_strcmp(instruction, "pa"))
		ft_btoa(stacks);
	if (!ft_strcmp(instruction, "pb"))
		ft_atob(stacks);
	if (!ft_strcmp(instruction, "rrb"))
		ft_revrotateb(stacks);
	if (!ft_strcmp(instruction, "rra"))
		ft_revrotatea(stacks);
	if (!ft_strcmp(instruction, "rrr"))
		ft_revrotatea(stacks) && ft_revrotateb(stacks);
}

void	threesort(t_stacks *stacks)
{
	if (stacks->mystack->elem > stacks->mystack->next->elem)
	{
		if (stacks->mystack->next->elem > stacks->mystack->next->next->elem)
		{
			ft_execwrite("sa", stacks);
			ft_execwrite("rra", stacks);
		}
		else if (stacks->mystack->next->next->elem > stacks->mystack->elem)
			ft_execwrite("sa", stacks);
		else
			ft_execwrite("ra", stacks);
	}
	else
	{
		if (stacks->mystack->next->next->elem > stacks->mystack->elem)
		{
			ft_execwrite("sa", stacks);
			ft_execwrite("ra", stacks);
		}
		else
			ft_execwrite("rra", stacks);
	}
}

int	ft_ismin(t_stack *stack, int size)
{
	int	i;
	int	min;

	i = 0;
	min = stack->elem;
	while (stack)
	{
		if (stack->elem < min)
			min = stack->elem;
		if (stack->next)
			stack = stack->next;
		else
			break;
	}
	while (stack && stack->prev)
		stack = stack->prev;
	while(stack && stack->elem != min)
	{
		stack = stack->next;
		i++;
	}
	return ((i != 0) + (i > size / 2));
}

void	printstack(t_stack *stack)
{
	while (stack)
	{
		printf("%d ", stack->elem);
		stack = stack->next;
	}
	printf("\n");
}

void	fivesort(t_stacks *stacks)
{
	int	i;

	i = 0;
	while(stacks->size - i > 3)
	{
		if (ft_ismin(stacks->mystack, stacks->size - i) == 1)
			ft_execwrite("ra", stacks);
		else if (ft_ismin(stacks->mystack, stacks->size - i) == 2)
			ft_execwrite("rra",stacks);
		else
		{
			ft_execwrite("pb",stacks);
			i++;
		}
	}
	if (stacks->sorted && stacks->sorted->next)
		if (stacks->sorted->elem < stacks->sorted->next->elem)
			ft_execwrite("rb", stacks);
	threesort(stacks);
	while(stacks->sorted)
		ft_execwrite("pa", stacks);
}

void	gosort(t_stacks *stacks)
{
	if (stacks->size <= 5)
	{
		if(stacks->size == 2)
			write(1, "ra\n", 3);
		else if (stacks->size == 3)
			threesort(stacks);
		else if (stacks->size > 3)
			fivesort(stacks);
	}
	else
		;
}

void	ft_startwork(char **av)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->sorted = malloc(sizeof(t_stack));
	stacks->sorted = NULL;
	stacks->mystack = ft_filla(av);
	stacks->size = ft_count(stacks->mystack);
	while(stacks->mystack->prev)
		stacks->mystack = stacks->mystack->prev;
	if (!issorted(stacks->mystack))
		gosort(stacks);
	//printstack(stacks->mystack);
}
