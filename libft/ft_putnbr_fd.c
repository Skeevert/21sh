/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 22:02:51 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/07 22:09:57 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	buf;

	buf = n;
	if (buf < 0)
	{
		ft_putchar_fd('-', fd);
		buf *= -1;
	}
	if (buf > 9)
	{
		ft_putnbr_fd(buf / 10, fd);
		ft_putnbr_fd(buf % 10, fd);
	}
	else
		ft_putchar_fd(buf + '0', fd);
}
