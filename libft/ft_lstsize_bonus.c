#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	c;

	c = 0;
	while (lst)
	{
		lst = lst->next;
		c++;
	}
	return (c);
}
