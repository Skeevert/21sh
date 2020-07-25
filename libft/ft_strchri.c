/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 13:37:06 by rbednar           #+#    #+#             */
/*   Updated: 2020/05/29 22:14:51 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strchri(char *s, int c)
{
	size_t			*iter;
	char			*end;
	size_t			mask;
	int				i;

	mask = 0;
	i = -1;
	while (++i < (int)sizeof(size_t))
		mask |= ((size_t)(1 + (size_t)c) << ((size_t)i * 8));
	end = (char *)s;
	while ((size_t)end % sizeof(size_t))
	{
		if (*end == (unsigned char)c || *end == '\0')
			return (*end == (char)c ? (int)(end - s) : -1);
		++end;
	}
	iter = (size_t *)end;
	while (((*iter - mask) & ~(*iter) & 0x8080808080808080) == 0 &&
			((*iter - 0x0101010101010101) & ~(*iter) & 0x8080808080808080) == 0)
		iter++;
	end = (char *)iter;
	while (*end && *end != (char)c)
		++end;
	return (*end == (char)c ? (int)(end - s) : -1);
}
