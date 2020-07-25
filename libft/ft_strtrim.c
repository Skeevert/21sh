/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:28:58 by rbednar           #+#    #+#             */
/*   Updated: 2018/12/10 23:16:17 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*buf;
	size_t	k;
	size_t	st;
	size_t	f;

	k = 0;
	if (s)
	{
		while ((s[k] == ' ' || s[k] == '\n' || s[k] == '\t') && s[k])
			k++;
		st = k;
		if (st == ft_strlen(s))
			return (ft_strnew(0));
		k = ft_strlen(s) - 1;
		while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
			k--;
		f = k + 1;
		buf = ft_strnew(f - st);
		if (buf && f != st)
		{
			ft_strlcat(buf, &s[st], f - st + 1);
			return (buf);
		}
	}
	return (NULL);
}
