/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <fcraydle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:44:03 by fcraydle          #+#    #+#             */
/*   Updated: 2019/09/20 17:44:03 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

size_t	ft_strlen_pf(const char *s)
{
	char *tmp;

	if (s)
	{
		tmp = (char*)s;
		while (*tmp)
			tmp++;
		return (tmp - s);
	}
	return (0);
}
