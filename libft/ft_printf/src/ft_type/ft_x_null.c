/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:48:41 by fcraydle          #+#    #+#             */
/*   Updated: 2019/10/15 20:53:29 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_minus_neg_null(t_param list, int tmp, t_buf *buf)
{
	if ((list.width - (list.precision > tmp ? list.precision : tmp) -
										list.hasht) >= 0 && list.zero != 1)
		ft_buf_add_s(buf, ft_memnew_pf(list.width - (list.precision > tmp ?
			list.precision : tmp) -
				(list.hasht == 1 && list.precision == -1), ' '), 0);
	if (list.precision == -1)
		ft_buf_add_s(buf, "0", 1);
	if ((list.width - (list.precision > tmp ? list.precision : tmp) -
										list.hasht) > 0 && list.zero == 1)
		ft_buf_add_s(buf, ft_memnew_pf(list.width - tmp -
			(list.hasht == 1 && list.precision == -1), '0'), 0);
	if (list.precision > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.precision - tmp, '0'), 0);
}

void	ft_minus_pos_null(t_param list, int tmp, t_buf *buf)
{
	if (list.precision == -1)
		ft_buf_add_s(buf, "0", 1);
	if (list.precision > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.precision - tmp, '0'), 0);
	if ((list.width - (list.precision > tmp ? list.precision : tmp) -
										list.hasht) >= 0 && list.zero != 1)
		ft_buf_add_s(buf,
			ft_memnew_pf(list.width - (list.precision > tmp ? list.precision
				: tmp) - (list.hasht == 1 && list.precision == -1), ' '), 0);
}
