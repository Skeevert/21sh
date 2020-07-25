/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddsy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:19:34 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:19:35 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "help_lib.h"

char		*ft_straddsy(char *dest, char sy)
{
	int		i;

	i = 0;
	while (dest[i])
		i++;
	dest[i] = sy;
	return (dest);
}
