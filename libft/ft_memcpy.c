/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 22:03:52 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/26 19:32:25 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	i = -1;
	while (++i < n)
		((unsigned char*)dst)[i] = ((const unsigned char*)src)[i];
	return ((unsigned char*)dst);
}
