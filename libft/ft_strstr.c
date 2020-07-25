/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:14:26 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/09 19:56:34 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	k;
	char	*h;
	char	*n;

	h = (char *)haystack;
	n = (char *)needle;
	if (!ft_strlen(n) || h == n)
		return (h);
	i = 0;
	while (h[i])
	{
		k = 0;
		if (h[i] == n[k])
		{
			while (n[k] && h[i + k] && n[k] == h[i + k])
				k++;
			if ((!n[k] && !h[i + k]) || (!n[k] && h[i + k]))
				return (&h[i]);
		}
		i++;
	}
	return (NULL);
}
