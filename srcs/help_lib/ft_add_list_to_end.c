/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_list_to_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:18:53 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:18:54 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "help_lib.h"

void		ft_add_list_to_end(t_list **start, t_list *new)
{
	t_list	*tmp;

	tmp = *start;
	if (*start && new)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else if (*start == NULL)
		*start = new;
}
