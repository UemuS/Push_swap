#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

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
void	freethestack(t_stacks *stacks);
void	ft_execwrite(char *instruction, t_stacks *stacks);
t_stack	*ft_filla(char **av);
void	ft_startwork(char **av);
int		ft_checkint(char **av);
int		ft_count(t_stack *stack);
void	ft_error(void);
int		ft_size(char *nmb);
#endif