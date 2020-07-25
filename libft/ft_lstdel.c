/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:25:54 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/22 21:42:55 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (alst)
	{
		tmp = *alst;
		while (*alst)
		{
			tmp = tmp->next;
			ft_lstdelone(alst, del);
			*alst = tmp;
		}
	}
}
