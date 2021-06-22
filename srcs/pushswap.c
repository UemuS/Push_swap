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

void	ft_startwork(char **av)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->sorted = malloc(sizeof(t_stack));
	stacks->sorted = NULL;
	stacks->mystack = ft_filla(av);
	stacks->size = ft_count(stacks->mystack);
	printf("first\n");
	while(stacks->mystack)
	{
		printf("%d\n", stacks->mystack->elem);
		if(stacks->mystack->next)
			stacks->mystack = stacks->mystack->next;
		else
			break;
	}
	while(stacks->mystack->prev)
		stacks->mystack = stacks->mystack->prev;
	printf("after rotation\n");
	ft_atob(stacks);
	while(stacks->mystack)
	{
		printf("%d\n", stacks->mystack->elem);
		if(stacks->mystack->next)
			stacks->mystack = stacks->mystack->next;
		else
			break;
	}
	while(stacks->mystack->prev)
		stacks->mystack = stacks->mystack->prev;
	printf("b\n");
	while(stacks->sorted)
	{
		printf("%d\n", stacks->sorted->elem);
		if(stacks->sorted->next)
			stacks->sorted = stacks->sorted->next;
		else
			break;
	}
}
