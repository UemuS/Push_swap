#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_stack
{
	int				el;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_stacks
{
	t_stack		*mya;
	t_stack		*sorted;
	int			*srt;
	int			size;
}				t_stacks;

int		ft_revrotateb(t_stacks *stacks);
int		ft_revrotatea(t_stacks *stacks);
int		ft_btoa(t_stacks *stacks);
int		ft_atob(t_stacks *stacks);
int		ft_rotatea(t_stacks *stacks);
int		ft_rotateb(t_stacks *stacks);
int		ft_swapa(t_stacks *stacks);
int		ft_swapb(t_stacks *stacks);

void	ft_execwrite(char *instruction, t_stacks *stacks);

void	bigsort(t_stacks *stacks);
void	fivesort(t_stacks *stacks);
void	threesort(t_stacks *stacks);
int		issorted(t_stack *stack);
void	ft_radix(t_stacks *stacks);
void	selectionsort(int arr[], int n);
int		ft_index(int *srt, int el, int max);
void	freethestack(t_stacks *stacks);

void	ft_startwork(char **av);

#endif