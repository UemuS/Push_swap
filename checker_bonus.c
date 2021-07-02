#include "checker_bonus.h"

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

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (255);
}

int	ft_size(char *nmb)
{
	if (ft_strlen(nmb) > 11 || ft_atoi(nmb) > INT_MAX
		|| ft_atoi(nmb) < INT_MIN)
		return (1);
	return (0);
}

int	ft_checkrep(char **av, char *cmp, int max)
{
	int	i;

	i = -1;
	while (++i < max)
		if (!ft_strcmp(av[i], cmp))
			return (1);
	return (0);
}

int	ft_checkint(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' && !av[i][j + 1])
			return (1);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && (j != 0 || av[i][j] != '-'))
				return (1);
			j++;
		}
		if (ft_size(av[i]))
			return (1);
		if (ft_checkrep(av, av[i], i))
			return (1);
		i++;
	}
	return (0);
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

t_stack	*ft_mallocatoi(char *str)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->el = (int)ft_atoi(str);
	return (a);
}

t_stack	*ft_filla(char **av)
{
	t_stack	*next;
	t_stack	*prev;
	int		i;

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
	int		ret;
	int		size;

	size = stacks->size;
	while ((ret = get_next_line(0, &line)) > 0)
		ft_execorerror(line, stacks, 0);
	if (ret == 0)
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
