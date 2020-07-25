/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:18:34 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:18:35 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "help_lib.h"

int				ft_last_stack(t_stack **head)
{
	t_stack		*tmp;

	tmp = *head;
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	return (tmp->data);
}
