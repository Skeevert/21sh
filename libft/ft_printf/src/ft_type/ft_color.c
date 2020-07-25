/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <fcraydle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:46:37 by fcraydle          #+#    #+#             */
/*   Updated: 2019/09/20 17:46:37 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

char	*ft_colours(char *str, t_buf *buf)
{
	char	*tmp;
	char	*color;

	tmp = str;
	if (tmp == NULL)
		return (NULL);
	while (tmp && *tmp != '}')
	{
		if (*tmp < '0' || *tmp > '9')
			return (str - 1);
		tmp++;
	}
	if (*tmp != '}')
		return (str - 1);
	color = ft_strndup_pf(str, tmp - str);
	ft_buf_add_s(buf, "\033[38;5;", 1);
	ft_buf_add_s(buf, color, 0);
	ft_buf_add_c(buf, 'm');
	return (tmp);
}
