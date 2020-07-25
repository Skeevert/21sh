/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 23:21:26 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/09 23:42:17 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*buf;
	size_t	i;

	if (s && f)
	{
		buf = ft_strnew(ft_strlen(s));
		if (buf)
		{
			i = 0;
			while (s[i])
			{
				buf[i] = f(s[i]);
				i++;
			}
			return (buf);
		}
	}
	return (NULL);
}
