#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		new = (t_list*)malloc(sizeof((*f)(lst)));
		lst = lst->next;
		new = new->next;
	}
	while (new)
	{
		(*f)(new);
		new = new->next;
	}
	return (new);
}
