/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:08:48 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/09 20:10:35 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	i;
	unsigned char	m;
	size_t			j;

	j = 0;
	while (s1[j] && s2[j] && s1[j] == s2[j])
		j++;
	i = (unsigned char)s1[j];
	m = (unsigned char)s2[j];
	return ((int)(i - m));
}
