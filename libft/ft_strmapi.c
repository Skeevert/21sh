/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 23:43:13 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/09 23:45:01 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*buf;
	unsigned int	i;

	if (s && f)
	{
		buf = ft_strnew(ft_strlen(s));
		if (buf)
		{
			i = 0;
			while (s[i])
			{
				buf[i] = f(i, s[i]);
				i++;
			}
			return (buf);
		}
	}
	return (NULL);
}
