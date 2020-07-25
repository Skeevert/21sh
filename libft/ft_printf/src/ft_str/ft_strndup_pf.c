/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <fcraydle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:44:21 by fcraydle          #+#    #+#             */
/*   Updated: 2019/09/20 17:44:21 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

char		*ft_strndup_pf(const char *s1, size_t n)
{
	char	*new_s1;
	char	*tmp;

	if (!(new_s1 = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	tmp = new_s1;
	while ((int)n--)
	{
		*new_s1 = *s1;
		new_s1++;
		s1++;
	}
	*new_s1 = '\0';
	return (tmp);
}
