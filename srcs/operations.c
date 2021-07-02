#include "pushswap.h"

int	ft_rotatea(t_stacks *stacks)
{
	t_stack	*head;
	int		i;

	i = 0;
	if (!stacks->mya || !stacks->mya->next)
		return (0);
	head = stacks->mya;
	while (stacks->mya)
	{
		i++;
		if (i == 2)
			stacks->mya->prev = NULL;
		if (stacks->mya->next)
			stacks->mya = stacks->mya->next;
		else
		{
			stacks->mya->next = head;
			head->prev = stacks->mya;
			head->next = NULL;
			break ;
		}
	}
	while (stacks->mya->prev)
		stacks->mya = stacks->mya->prev;
	return (1);
}

int	ft_rotateb(t_stacks *stacks)
{
	t_stack	*head;
	int		i;

	if (!stacks->sorted || !stacks->sorted->next)
		return (0);
	i = 0;
	head = stacks->sorted;
	while (stacks->sorted)
	{
		i++;
		if (i == 2)
			stacks->sorted->prev = NULL;
		if (stacks->sorted->next)
			stacks->sorted = stacks->sorted->next;
		else
		{
			stacks->sorted->next = head;
			head->prev = stacks->sorted;
			head->next = NULL;
			break ;
		}
	}
	while (stacks->sorted->prev)
		stacks->sorted = stacks->sorted->prev;
	return (1);
}

int	ft_atob(t_stacks *stacks)
{
	t_stack	*head;

	if (!stacks->mya)
		return (0);
	head = stacks->mya->next;
	stacks->mya->next->prev = NULL;
	stacks->mya->next = NULL;
	if (!stacks->sorted)
		stacks->sorted = stacks->mya;
	else
	{
		stacks->sorted->prev = stacks->mya;
		stacks->sorted->prev->next = stacks->sorted;
		stacks->sorted = stacks->sorted->prev;
	}
	stacks->mya = head;
	return (1);
}

int	ft_btoa(t_stacks *stacks)
{
	t_stack	*head;

	if (!stacks->sorted)
		return (0);
	head = stacks->sorted->next;
	if (stacks->sorted->next)
		stacks->sorted->next->prev = NULL;
	stacks->sorted->next = NULL;
	if (!stacks->mya)
		stacks->mya = stacks->sorted;
	else
	{
		stacks->mya->prev = stacks->sorted;
		stacks->mya->prev->next = stacks->mya;
		stacks->mya = stacks->mya->prev;
	}
	stacks->sorted = head;
	return (1);
}

int	ft_revrotatea(t_stacks *stacks)
{
	t_stack	*head;

	if (!stacks->mya || !stacks->mya->next)
		return (0);
	head = stacks->mya;
	while (stacks->mya)
	{
		if (stacks->mya->next)
			stacks->mya = stacks->mya->next;
		else
		{
			if (stacks->mya->prev)
				stacks->mya->prev->next = NULL;
			stacks->mya->prev = NULL;
			stacks->mya->next = head;
			head->prev = stacks->mya;
			break ;
		}
	}
	while (stacks->mya->prev)
		stacks->mya = stacks->mya->prev;
	return (1);
}
