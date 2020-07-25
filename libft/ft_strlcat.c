/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 23:28:01 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/26 19:46:01 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	s;

	i = ft_strlen(dst);
	s = ft_strlen(src);
	k = 0;
	if (size > 0)
	{
		while (src[k] && k < (size - i - 1) && size > i)
		{
			dst[i + k] = src[k];
			k++;
		}
		if (size > i)
			(dst[i + k] = '\0');
	}
	if (i > size)
		return (s + size);
	else
		return (i + s);
}
