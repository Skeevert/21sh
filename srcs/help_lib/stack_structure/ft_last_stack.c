/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladlenaskubis <vladlenaskubis@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:00:43 by sschmele          #+#    #+#             */
/*   Updated: 2020/03/27 19:23:14 by vladlenasku      ###   ########.fr       */
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
