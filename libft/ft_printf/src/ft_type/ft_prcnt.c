/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prcnt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:47:44 by fcraydle          #+#    #+#             */
/*   Updated: 2019/10/15 20:50:34 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_prcnt(t_param list, t_buf *buf)
{
	if (list.minus == 0 && list.zero == 1 && list.width > 1)
		ft_buf_add_s(buf,
			ft_memset_pf(ft_strnew_pf(list.width - 1), '0', list.width - 1), 0);
	else if (list.width > 1 && list.minus == 0)
		ft_buf_add_s(buf,
			ft_memset_pf(ft_strnew_pf(list.width - 1), ' ', list.width - 1), 0);
	ft_buf_add_c(buf, '%');
	if (list.width > 1 && list.minus == 1)
		ft_buf_add_s(buf,
			ft_memset_pf(ft_strnew_pf(list.width - 1), ' ', list.width - 1), 0);
}
