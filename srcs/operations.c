#include "pushswap.h"

void	ft_rotatea(t_stacks *stacks)
{
	t_stack	*head;
	int			i;

	i = 0;
	head = stacks->mystack;
	while(stacks->mystack)
	{
		i++;
		if(i == 2)
			stacks->mystack->prev = NULL;
		if (stacks->mystack->next)
			stacks->mystack = stacks->mystack->next;
		else
		{
				stacks->mystack->next = head;
				head->prev = stacks->mystack;
				head->next = NULL;
				break;
		}
	}
	while(stacks->mystack->prev)
		stacks->mystack = stacks->mystack->prev;
}

void	ft_rotateb(t_stacks *stacks)
{
	t_stack	*head;
	int			i;

	i = 0;
	head = stacks->sorted;
	while(stacks->sorted)
	{
		i++;
		if(i == 2)
			stacks->sorted->prev = NULL;
		if (stacks->sorted->next)
			stacks->sorted = stacks->sorted->next;
		else
		{
				stacks->sorted->next = head;
				head->prev = stacks->sorted;
				head->next = NULL;
				break;
		}
	}
	while(stacks->sorted->prev)
		stacks->sorted = stacks->sorted->prev;
}

void	ft_atob(t_stacks *stacks)
{
	t_stack *head;

	head = stacks->mystack->next;
	stacks->mystack->next->prev = NULL;
	stacks->mystack->next = NULL;
	if (!stacks->sorted)
		stacks->sorted = stacks->mystack;
	else
	{
		stacks->sorted->prev = stacks->mystack;
		stacks->sorted->prev->next = stacks->sorted;
		stacks->sorted = stacks->sorted->prev;
	}
	stacks->mystack = head;
}