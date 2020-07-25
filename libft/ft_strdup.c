/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 22:18:32 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/07 22:37:28 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buf;
	size_t	k;

	k = 0;
	while (s1[k])
		k++;
	buf = (char *)malloc(sizeof(char) * k + 1);
	if (buf == NULL)
		return (NULL);
	else
	{
		buf[k] = '\0';
		while (--k + 1 > 0)
			buf[k] = s1[k];
	}
	return (buf);
}
