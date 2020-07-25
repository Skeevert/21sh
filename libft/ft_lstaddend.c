/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 22:10:22 by rbednar           #+#    #+#             */
/*   Updated: 2019/10/11 14:30:13 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstaddend(t_list **alst, t_list **new)
{
	t_list	*start;

	if (!(alst) || !(*alst))
		return (NULL);
	start = *alst;
	while (start->next)
		start = start->next;
	start->next = *new;
	return (*alst);
}
