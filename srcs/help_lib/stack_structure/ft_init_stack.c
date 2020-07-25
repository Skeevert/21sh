/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:18:26 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:18:27 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "help_lib.h"

t_stack				*ft_init_stack(void)
{
	t_stack			*stack;

	stack = ft_xmalloc(sizeof(t_stack));
	stack->data = 0;
	stack->next = NULL;
	return (stack);
}
