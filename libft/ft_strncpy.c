/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 22:53:50 by rbednar           #+#    #+#             */
/*   Updated: 2020/08/04 16:50:05 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	k;

	k = 0;
	if (len > 0)
		while (src[k] && k < len)
		{
			dst[k] = src[k];
			k++;
		}
	while (k < len)
	{
		dst[k] = '\0';
		k++;
	}
	return (dst);
}
