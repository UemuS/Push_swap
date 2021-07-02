#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*front;

	if (!new)
		return ;
	if (!alst || !*alst)
	{
		*alst = new;
		return ;
	}
	front = new;
	front->next = malloc(sizeof(t_list));
	front->next = *alst;
	*alst = front;
}
