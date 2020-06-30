/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladlenaskubis <vladlenaskubis@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 10:32:02 by sschmele          #+#    #+#             */
/*   Updated: 2020/03/27 19:23:14 by vladlenasku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "help_lib.h"

int					ft_push_stack(t_stack **head, int data)
{
	t_stack			*tmp;

	tmp = (t_stack*)ft_xmalloc(sizeof(t_stack));
	tmp->next = *head;
	tmp->data = data;
	*head = tmp;
	return (0);
}
