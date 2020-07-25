/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:09:26 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/14 21:34:44 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	i;
	unsigned char	m;
	size_t			j;

	if (n == 0)
		return (0);
	j = 0;
	while (s1[j] && s2[j] && s1[j] == s2[j] && j < n - 1)
		j++;
	i = (unsigned char)s1[j];
	m = (unsigned char)s2[j];
	return ((int)(i - m));
}
