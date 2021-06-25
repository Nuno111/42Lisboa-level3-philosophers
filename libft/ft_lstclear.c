/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngregori <ngregori@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 00:03:40 by ngregori          #+#    #+#             */
/*   Updated: 2021/05/23 12:44:04 by ngregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (*lst)
	{
		while (*lst != NULL)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			if (del)
				del(tmp->content);
			else
				tmp->content = NULL;
			free(tmp);
		}
		lst = NULL;
	}
}
