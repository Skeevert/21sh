/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_dig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <fcraydle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:49:57 by fcraydle          #+#    #+#             */
/*   Updated: 2019/09/20 17:49:57 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_num_dig(uintmax_t n, int base)
{
	int res;

	res = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		res++;
		n /= base;
	}
	return (res);
}
