/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 23:18:28 by rbednar           #+#    #+#             */
/*   Updated: 2019/01/11 23:51:19 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define GIVE ft_give_me

static	char	*ft_strcpy_word(char const *s, size_t len)
{
	char	*k;

	k = ft_strnew(len);
	if (s && len > 0 && k)
	{
		return (ft_strncpy(k, s, len));
	}
	return (NULL);
}

static	size_t	ft_count(char const *s, char c)
{
	size_t	k;
	size_t	i;

	k = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			k++;
		}
		i++;
	}
	return (k);
}

static	char	**ft_free_buf(char **buf, size_t i)
{
	size_t	k;

	k = 0;
	while (k < i)
	{
		free(buf[k]);
		k++;
	}
	free(buf);
	return (NULL);
}

static	t_word	ft_give_me(char *s, char c)
{
	t_word	k;
	size_t	i;
	size_t	l;

	i = 0;
	while (s[i] == c && s[i])
		i++;
	k.point = (char *)&s[i];
	l = 0;
	while (s[i] != c && s[i])
	{
		l++;
		i++;
	}
	k.len = l;
	return (k);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**buf;
	size_t	i;
	char	*k;
	size_t	count;

	i = -1;
	if (!s)
		return (NULL);
	count = ft_count(s, c);
	buf = (char**)malloc(sizeof(char**) * (count + 1));
	if (buf)
	{
		k = (char*)s;
		while (++i < count)
		{
			if (GIVE(k, c).len != 0 && *s != '\0')
				buf[i] = ft_strcpy_word(GIVE(k, c).point, GIVE(k, c).len);
			if (buf[i] == NULL)
				return (ft_free_buf(buf, i));
			k = GIVE(k, c).point + GIVE(k, c).len;
		}
		buf[count] = NULL;
	}
	return (buf);
}
