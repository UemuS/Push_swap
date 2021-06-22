#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_stacka
{
	int				elem_a;
	struct s_stacka	*next;
	struct s_stacka	*prev;
}				t_stacka;

typedef struct s_stackb
{
	long			elem_b;
	struct s_stackb	*next;
	struct s_stackb	*prev;
}				t_stackb;

typedef struct s_stacks
{
	t_stacka	*mystack;
	t_stackb	*sorted;
	int			size;
}				t_stacks;

void	ft_startwork(char **av);

#endif