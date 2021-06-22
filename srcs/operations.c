#include "pushswap.h"

void	ft_rotatea(t_stacks *stacks)
{
	t_stack	*head;
	int			i;

	i = 0;
	if (!stacks->mystack || !stacks->mystack->next)
		return ;
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

	if (!stacks->sorted || !stacks->sorted->next)
		return ;
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

	if (!stacks->mystack)
		return ;
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

void	ft_btoa(t_stacks *stacks)
{
	t_stack *head;

	if (!stacks->sorted)
		return ;
	head = stacks->sorted->next;
	if (stacks->sorted->next)
		stacks->sorted->next->prev = NULL;
	stacks->sorted->next = NULL;
	if (!stacks->mystack)
		stacks->mystack = stacks->sorted;
	else
	{
		stacks->mystack->prev = stacks->sorted;
		stacks->mystack->prev->next = stacks->mystack;
		stacks->mystack = stacks->mystack->prev;
	}
	stacks->sorted = head;
}

void	ft_revrotatea(t_stacks *stacks)
{
	t_stack	*head;

	if (!stacks->mystack || !stacks->mystack->next)
		return ;
	head = stacks->mystack;
	while(stacks->mystack)
	{
		
		if (stacks->mystack->next)
			stacks->mystack = stacks->mystack->next;
		else
		{
			if (stacks->mystack->prev)
				stacks->mystack->prev->next = NULL;
			stacks->mystack->prev = NULL;
			stacks->mystack->next = head;
			head->prev = stacks->mystack;
			break;
		}
	}
	while(stacks->mystack->prev)
		stacks->mystack = stacks->mystack->prev;
}

void	ft_revrotateb(t_stacks *stacks)
{
	t_stack	*head;

	if (!stacks->sorted || !stacks->sorted->next)
		return ;
	head = stacks->sorted;
	while(stacks->sorted)
	{
		
		if (stacks->sorted->next)
			stacks->sorted = stacks->sorted->next;
		else
		{
			if (stacks->sorted->prev)
				stacks->sorted->prev->next = NULL;
			stacks->sorted->prev = NULL;
			stacks->sorted->next = head;
			head->prev = stacks->sorted;
			break;
		}
	}
	while(stacks->sorted->prev)
		stacks->sorted = stacks->sorted->prev;
}

void	ft_swapa(t_stacks *stacks)
{
	t_stack *oldhead;
	t_stack *newhead;

	if (!stacks->mystack || !stacks->mystack->next)
		return ;
	oldhead = stacks->mystack;
	newhead = stacks->mystack->next;
	if (stacks->mystack->next->next)
		stacks->mystack->next->next->prev = oldhead;
	stacks->mystack->next = stacks->mystack->next->next;
	stacks->mystack->prev = newhead;
	newhead->prev = NULL;
	newhead->next = oldhead;
	stacks->mystack = stacks->mystack->prev;
}

void	ft_swapb(t_stacks *stacks)
{
	t_stack *oldhead;
	t_stack *newhead;

	if (!stacks->sorted || !stacks->sorted->next)
		return ;
	oldhead = stacks->sorted;
	newhead = stacks->sorted->next;
	if (stacks->sorted->next->next)
		stacks->sorted->next->next->prev = oldhead;
	stacks->sorted->next = stacks->sorted->next->next;
	stacks->sorted->prev = newhead;
	newhead->prev = NULL;
	newhead->next = oldhead;
	stacks->sorted = stacks->sorted->prev;
}