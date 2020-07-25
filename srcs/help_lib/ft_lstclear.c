/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:19:16 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:19:17 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "help_lib.h"

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
