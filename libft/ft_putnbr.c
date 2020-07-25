/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 21:29:48 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/07 22:01:28 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int	buf;

	buf = n;
	if (buf < 0)
	{
		ft_putchar('-');
		buf *= -1;
	}
	if (buf > 9)
	{
		ft_putnbr(buf / 10);
		ft_putnbr(buf % 10);
	}
	else
		ft_putchar(buf + '0');
}
