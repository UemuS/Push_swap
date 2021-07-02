#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	nlst = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		ft_lstadd_back(&nlst, tmp);
		lst = lst->next;
	}
	return (nlst);
}
