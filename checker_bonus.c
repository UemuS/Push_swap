#include "checker_bonus.h"

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

void	ft_execorerror(char *instruction, t_stacks *stacks, int a)
{
	if (!ft_strcmp(instruction, "sa"))
		ft_swapa(stacks);
	else if (!ft_strcmp(instruction, "sb"))
		ft_swapb(stacks);
	else if (!ft_strcmp(instruction, "ss"))
		ft_swapa(stacks) && ft_swapb(stacks);
	else if (!ft_strcmp(instruction, "ra"))
		ft_rotatea(stacks);
	else if (!ft_strcmp(instruction, "rb"))
		ft_rotateb(stacks);
	else if (!ft_strcmp(instruction, "rr"))
		ft_rotatea(stacks) && ft_rotateb(stacks);
	else if (!ft_strcmp(instruction, "pa"))
		ft_btoa(stacks);
	else if (!ft_strcmp(instruction, "pb"))
		ft_atob(stacks);
	else if (!ft_strcmp(instruction, "rrb"))
		ft_revrotateb(stacks);
	else if (!ft_strcmp(instruction, "rra"))
		ft_revrotatea(stacks);
	else if (!ft_strcmp(instruction, "rrr"))
		ft_revrotatea(stacks) && ft_revrotateb(stacks);
	else if (a == 0)
		ft_error();
}

void	ft_readline(t_stacks *stacks)
{
	char	*line;
	int		size;

	size = (int)stacks->size;
	while (get_next_line(0, &line) > 0)
		ft_execorerror(line, stacks, 0);
	ft_execorerror(line, stacks, 1);
	if (issorted(stacks->mya) && size == ft_count(stacks->mya))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	ft_startwork(char **av)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->sorted = NULL;
	stacks->mya = ft_filla(av);
	stacks->size = ft_count(stacks->mya);
	while (stacks->mya->prev)
		stacks->mya = stacks->mya->prev;
	ft_readline(stacks);
	freethestack(stacks);
}

int	main(int ac, char **av)
{
	if (ft_checkint(av))
		ft_error();
	if (ac < 2)
		return (0);
	ft_startwork(av);
	return (0);
}
