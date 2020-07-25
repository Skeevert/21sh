/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <fcraydle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:43:44 by fcraydle          #+#    #+#             */
/*   Updated: 2019/09/20 17:43:44 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	*ft_memset_pf(void *b, int c, size_t len)
{
	unsigned char	*res;

	res = (unsigned char *)b;
	while (len--)
	{
		*res = c;
		res++;
	}
	return (b);
}
