/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:41:46 by fcraydle          #+#    #+#             */
/*   Updated: 2019/10/15 20:49:27 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void			ft_prec_neg_null(char *str, t_param list, t_buf *buf)
{
	int tmp;

	tmp = 0;
	list.hasht == 0 ? tmp = 1 : 0;
	if (list.minus == 0 && list.zero == 1 && list.width - list.hasht > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.width - list.hasht - tmp, '0'), 0);
	else if (list.minus == 0 && list.zero == 0 && list.width - list.hasht > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.width - list.hasht - tmp, ' '), 0);
	list.hasht == 1 ? ft_buf_add_c(buf, '0') : 0;
	list.hasht != 1 ? ft_buf_add_s(buf, str, 0) : 0;
	if (list.minus == 1 && list.width - list.hasht > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.width - list.hasht - tmp, ' '), 0);
}

void			ft_prec_pos_null(t_param list, t_buf *buf)
{
	if (list.minus == 0)
	{
		list.precision > -1 ? list.zero = 0 : 0;
		if (list.width > list.precision && list.zero == 0)
			ft_buf_add_s(buf, ft_memnew_pf(list.width - (list.hasht == 1 &&
				list.precision < 1) - list.precision, ' '), 0);
		else if (list.width > list.precision && list.zero == 1)
			ft_buf_add_s(buf, ft_memnew_pf(list.width - list.hasht -
				list.precision, '0'), 0);
		if (list.hasht == 1 && list.precision < 1)
			ft_buf_add_c(buf, '0');
		if (list.precision > 0)
			ft_buf_add_s(buf, ft_memnew_pf(list.precision, '0'), 0);
	}
	else
	{
		if (list.hasht == 1 && list.precision < 1)
			ft_buf_add_c(buf, '0');
		if (list.precision > 0)
			ft_buf_add_s(buf, ft_memnew_pf(list.precision, '0'), 0);
		if (list.width > list.precision && list.zero == 0)
			ft_buf_add_s(buf, ft_memnew_pf(list.width - (list.hasht == 1 &&
				list.precision < 1) - list.precision, ' '), 0);
	}
}
