/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:18:41 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:18:42 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "help_lib.h"

int				ft_pop_stack(t_stack **head)
{
	int			res;
	t_stack		*tmp;

	tmp = *head;
	if ((*head)->next)
		*head = (*head)->next;
	else
		return (0);
	res = tmp->data;
	free(tmp);
	return (res);
}
