#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmpl;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		tmpl = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = tmpl;
	}
}
