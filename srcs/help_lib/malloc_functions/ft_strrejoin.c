/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:17:47 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:17:48 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "help_lib.h"

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
		str = (char*)ft_xmalloc(len_1 + len_2 + 1);
		ft_strcat(str, s1);
		ft_strcat(str, s2);
	}
	ft_strdel(&s1);
	return (str);
}
