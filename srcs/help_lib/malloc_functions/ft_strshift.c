/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:52:47 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/22 16:52:49 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_strshift(char *str, int shift)
{
	char		*buff;
	int			i;

	if (str == (char*)NULL || str[0] == '\0')
		return ;
	buff = (char*)ft_xmalloc(ft_strlen(str) + 1);
	ft_strcpy(buff, str);
	ft_strcpy(str + shift, buff);
	i = 0;
	while (i < shift)
	{
		str[i] = '\0';
		i++;
	}
	free(buff);
}
