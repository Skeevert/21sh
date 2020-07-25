/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:13:36 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/20 22:53:32 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_long_fail(long num, long temp, int sign)
{
	if (num - temp < temp && sign > 0)
		return (-1);
	return (0);
}

int			ft_atoi(const char *str)
{
	size_t	i;
	long	num;
	int		sign;
	long	temp;

	sign = 1;
	i = 0;
	num = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		temp = num;
		num = 10 * num + (str[i] - '0');
		if (num - temp < temp)
			return (ft_long_fail(num, temp, sign));
		i++;
	}
	return (sign * (int)num);
}
