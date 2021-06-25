#include "libft.h"

t_list	*ft_lstduplicate(t_list *list)
{
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = NULL;
	if (!list)
		return (NULL);
	while (list)
	{
		new_node = ft_lstnew(list->content);
		ft_lstadd_back(&new_lst, new_node);
		list = list->next;
	}
	return (new_lst);
}
