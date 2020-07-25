/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 22:24:19 by rbednar           #+#    #+#             */
/*   Updated: 2019/01/11 22:30:18 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_list_clear(t_list **begin_list)
{
	t_list *tmp;

	while ((*begin_list)->next != NULL)
	{
		tmp = (*begin_list)->next;
		free((*begin_list));
		*begin_list = tmp;
	}
	*begin_list = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*buf;
	t_list	*del;

	if (!(lst))
		return (NULL);
	if (!(buf = f(lst)))
		return (NULL);
	del = buf;
	while (lst->next)
	{
		buf->next = f(lst->next);
		if (!(buf->next))
		{
			ft_list_clear(&del);
			return (NULL);
		}
		lst = lst->next;
		buf = buf->next;
	}
	return (del);
}
