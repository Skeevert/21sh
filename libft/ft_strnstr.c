/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:48:52 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/09 20:01:53 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
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
	while (h[i] && i < len)
	{
		k = 0;
		if (h[i] == n[k])
		{
			while (n[k] && h[i + k] && n[k] == h[i + k] && i + k < len)
				k++;
			if ((!n[k] && !h[i + k]) || (!n[k] && h[i + k]))
				return (&h[i]);
		}
		i++;
	}
	return (NULL);
}
