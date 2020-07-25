/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 22:45:34 by rbednar           #+#    #+#             */
/*   Updated: 2019/02/17 17:33:49 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **begin_list)
{
	t_list *tmp;

	if (!(begin_list) || !(*begin_list))
		return ;
	while (*begin_list)
	{
		tmp = (*begin_list)->next;
		if ((*begin_list)->content)
			free((*begin_list)->content);
		free((*begin_list));
		*begin_list = tmp;
	}
	*begin_list = NULL;
}
