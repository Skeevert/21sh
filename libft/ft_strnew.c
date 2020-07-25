/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 22:52:31 by rbednar           #+#    #+#             */
/*   Updated: 2020/05/29 22:16:58 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *buf;

	buf = (char *)malloc(sizeof(char) * (size + 1));
	if (!buf || size == (size_t)-1)
		return (NULL);
	ft_memset(buf, '\0', size + 1);
	return (buf);
}
