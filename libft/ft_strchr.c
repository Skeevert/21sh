/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:33:36 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/09 19:11:56 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	k;
	int		f;

	k = 0;
	f = 0;
	while (s[k] && s[k] != (char)c)
		k++;
	if (s[k] == (char)c)
		f = 1;
	if ((char)c == '\0')
		return ((char *)&s[k]);
	if (f > 0)
		return ((char *)&s[k]);
	return (NULL);
}
