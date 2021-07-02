#include "pushswap.h"

int	ft_revrotateb(t_stacks *stacks)
{
	t_stack	*head;

	if (!stacks->sorted || !stacks->sorted->next)
		return (0);
	head = stacks->sorted;
	while (stacks->sorted)
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
			break ;
		}
	}
	while (stacks->sorted->prev)
		stacks->sorted = stacks->sorted->prev;
	return (1);
}

int	ft_swapa(t_stacks *stacks)
{
	t_stack	*oldhead;
	t_stack	*newhead;

	if (!stacks->mya || !stacks->mya->next)
		return (0);
	oldhead = stacks->mya;
	newhead = stacks->mya->next;
	if (stacks->mya->next->next)
		stacks->mya->next->next->prev = oldhead;
	stacks->mya->next = stacks->mya->next->next;
	stacks->mya->prev = newhead;
	newhead->prev = NULL;
	newhead->next = oldhead;
	stacks->mya = stacks->mya->prev;
	return (1);
}

int	ft_swapb(t_stacks *stacks)
{
	t_stack	*oldhead;
	t_stack	*newhead;

	if (!stacks->sorted || !stacks->sorted->next)
		return (0);
	oldhead = stacks->sorted;
	newhead = stacks->sorted->next;
	if (stacks->sorted->next->next)
		stacks->sorted->next->next->prev = oldhead;
	stacks->sorted->next = stacks->sorted->next->next;
	stacks->sorted->prev = newhead;
	newhead->prev = NULL;
	newhead->next = oldhead;
	stacks->sorted = stacks->sorted->prev;
	return (1);
}
