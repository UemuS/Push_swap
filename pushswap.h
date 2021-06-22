#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_stacka
{
	int				*elem_a;
	struct t_stacka	*next;
	struct t_stacka	*prev;
}				t_stacka;

typedef struct s_stackb
{
	int				elem_b;
	struct t_stackb	*next;
	struct t_stackb	*prev;
}				t_stackb;

#endif