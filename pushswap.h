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

int	ft_revrotateb(t_stacks *stacks);
int	ft_revrotatea(t_stacks *stacks);
int	ft_btoa(t_stacks *stacks);
int	ft_atob(t_stacks *stacks);
int	ft_rotatea(t_stacks *stacks);
int	ft_rotateb(t_stacks *stacks);
int	ft_swapa(t_stacks *stacks);
int	ft_swapb(t_stacks *stacks);

void	printstack(t_stack *stack);
void	ft_startwork(char **av);

#endif