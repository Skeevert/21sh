/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:17:43 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:17:44 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "help_lib.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*temp;
	int		i;

	i = 0;
	if (!s1 || s1[0] == '\0')
		return (NULL);
	if ((n + 1) < n)
		return (NULL);
	temp = (char*)ft_xmalloc((n + 1) * sizeof(*s1));
	while (n)
	{
		temp[i] = s1[i];
		i++;
		n--;
	}
	return (temp);
}
