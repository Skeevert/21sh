/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:53:51 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/14 20:02:22 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int n)
{
	if (n >= 0)
		return (1);
	else
		return (-1);
}

char		*ft_itoa(int n)
{
	long int	nbr;
	long int	nbr2;
	int			i;
	char		*buf;

	i = 0;
	nbr2 = n;
	nbr = (long int)n * ft_sign(n);
	while ((nbr2 /= 10) != 0)
		i++;
	if (ft_sign(n) < 0)
		buf = ft_strnew(i += 2);
	else
		buf = ft_strnew(i += 1);
	if (!buf)
		return (NULL);
	while (i > 0)
	{
		buf[--i] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		buf[0] = '-';
	return (buf);
}
