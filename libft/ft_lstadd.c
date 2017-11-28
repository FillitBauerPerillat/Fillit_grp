#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *neww)
{
	neww->next = *alst;
	*alst = neww;
}
