#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_stack
{
	int				elem;
	struct s_stack	*next;
	struct s_stack	*prev;
}						t_stack;

typedef struct s_stacks
{
	t_stack	*mystack;
	t_stack	*sorted;
	int			size;
}				t_stacks;

void	ft_switch(t_stacks *stacks);
void	ft_btoa(t_stacks *stacks);
void	ft_atob(t_stacks *stacks);
void	ft_startwork(char **av);
void	ft_rotatea(t_stacks *stacks);

#endif