/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:14:00 by rbednar           #+#    #+#             */
/*   Updated: 2020/06/08 17:47:37 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char		*ft_strrejoin(char *s1, char *s2)
{
	char	*str;
	int		len_1;
	int		len_2;

	str = 0;
	if (s1 && s2)
	{
		len_1 = ft_strlen(s1);
		len_2 = ft_strlen(s2);
		if (!(str = ft_memalloc(len_1 + len_2 + 1)))
			return (NULL);
		ft_strcat(str, s1);
		ft_strcat(str, s2);
	}
	ft_strdel(&s1);
	return (str);
}
