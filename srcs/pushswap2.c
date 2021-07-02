#include "pushswap.h"

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

int	issorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->prev && stack->el < stack->prev->el)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	freethestack(t_stacks *stacks)
{
	t_stack	*head;

	while (stacks->mya)
	{
		head = stacks->mya;
		stacks->mya = stacks->mya->next;
		free(head);
	}
	while (stacks->sorted)
	{
		head = stacks->sorted;
		stacks->sorted = stacks->sorted->next;
		free(head);
	}
	free(stacks);
}

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	selectionsort(int arr[], int n)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	while (i < n - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		swap(&arr[min_idx], &arr[i]);
		i++;
	}
}
