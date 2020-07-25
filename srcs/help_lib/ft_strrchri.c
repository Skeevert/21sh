/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:19:42 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:22:55 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "help_lib.h"

int			ft_strrchri(char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == c)
		{
			p = (char*)s + i;
			break ;
		}
		i--;
	}
	if (i == 0 && p == 0)
		return (-1);
	return (p - s);
}
