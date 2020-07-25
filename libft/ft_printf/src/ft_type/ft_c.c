/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:31:44 by fcraydle          #+#    #+#             */
/*   Updated: 2019/10/15 20:46:47 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_c(t_param list, char c, t_buf *buf)
{
	if (list.minus == 0 && list.zero == 1 && list.width > 1)
		ft_buf_add_s(buf,
			ft_memset_pf(ft_strnew_pf(list.width - 1), '0', list.width - 1), 0);
	else if (list.minus == 0 && list.zero == 0 && list.width > 1)
		ft_buf_add_s(buf,
			ft_memset_pf(ft_strnew_pf(list.width - 1), ' ', list.width - 1), 0);
	ft_buf_add_c(buf, c);
	if (list.minus == 1 && list.width > 1)
		ft_buf_add_s(buf,
			ft_memset_pf(ft_strnew_pf(list.width - 1), ' ', list.width - 1), 0);
}
