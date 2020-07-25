/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:17:37 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:17:38 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "help_lib.h"

char	*ft_strdup(const char *s1)
{
	int		le;
	char	*temp;

	if (!s1)
		return ((char*)s1);
	le = ft_strlen(s1);
	temp = (char*)ft_xmalloc((le + 1) * sizeof(*s1));
	while (*s1 != '\0')
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	return (temp -= le);
}
