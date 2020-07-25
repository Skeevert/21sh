/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:19:21 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:19:22 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "libft.h"

t_list	*ft_lstlast(t_list **begin_list)
{
	t_list	*tmp;

	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
