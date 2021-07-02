#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!alst || !*alst)
	{
		*alst = new;
		return ;
	}
	last = malloc(sizeof(t_list));
	last = ft_lstlast(*alst);
	last->next = malloc(sizeof(t_list));
	last->next = new;
}
