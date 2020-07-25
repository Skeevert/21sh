/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:06:35 by rbednar           #+#    #+#             */
/*   Updated: 2020/06/08 17:48:35 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	k;
	int		f;
	char	*buf;

	k = 0;
	f = 0;
	while (s[k])
	{
		if (s[k] == (char)c)
		{
			f = 1;
			buf = (char *)&s[k];
		}
		k++;
	}
	if ((char)c == '\0')
		return ((char *)&s[k]);
	if (f > 0)
		return (buf);
	return (NULL);
}
