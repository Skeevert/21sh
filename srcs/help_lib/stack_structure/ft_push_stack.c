/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:18:47 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:18:48 by rbednar          ###   ########.fr       */
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
