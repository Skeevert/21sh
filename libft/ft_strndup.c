/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 23:45:47 by rbednar           #+#    #+#             */
/*   Updated: 2020/05/29 22:15:32 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*temp;
	int		i;

	i = 0;
	if (!s1 || s1[0] == '\0')
		return (NULL);
	if ((n + 1) < n)
		return (NULL);
	if (!(temp = (char*)malloc((n + 1) * sizeof(*s1))))
		return (NULL);
	while (n)
	{
		temp[i] = s1[i];
		i++;
		n--;
	}
	temp[i] = '\0';
	return (temp);
}
