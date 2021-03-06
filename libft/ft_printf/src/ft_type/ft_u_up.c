/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:48:22 by fcraydle          #+#    #+#             */
/*   Updated: 2019/10/15 20:51:03 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	minus_pos(char *i, t_param list, int tmp, t_buf *buf)
{
	if (list.precision > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.precision - tmp, '0'), 0);
	ft_buf_add_s(buf, i, 0);
	if (list.width > list.precision && list.width > tmp && list.zero == 1)
		ft_buf_add_s(buf, ft_memnew_pf(list.width - list.space -
			(list.precision > tmp ? list.precision : tmp), '0'), 0);
	if (list.width > list.precision && list.width > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.width - list.space -
			(list.precision > tmp ? list.precision : tmp), ' '), 0);
}

static void	prec_neg(char *i, t_param list, int tmp, t_buf *buf)
{
	if (list.minus == 0 && list.zero == 0 && list.width > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.width - tmp, ' '), 0);
	if (list.minus == 0 && list.zero == 1 && list.width > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.width - tmp, '0'), 0);
	ft_buf_add_s(buf, i, 0);
	if (list.minus == 1 && list.width > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.width - tmp, ' '), 0);
}

static void	prec_pos(char *i, t_param list, int tmp, t_buf *buf)
{
	*i == '0' && list.precision == 0 ? tmp -= 1 : 0;
	if (list.width > list.precision && list.width > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.width - list.space -
			(list.precision > tmp ? list.precision : tmp), ' '), 0);
	if (list.width > list.precision && list.width > tmp && list.zero == 1)
		ft_buf_add_s(buf, ft_memnew_pf(list.width - list.space -
			(list.precision > tmp ? list.precision : tmp), '0'), 0);
	if (list.precision > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.precision - tmp, '0'), 0);
	*i == '0' && list.precision == 0 ? NULL : ft_buf_add_s(buf, i, 0);
}

static void	ft_type_u(t_param list, char *i, t_buf *buf)
{
	list.precision > -1 ? list.zero = 0 : 0;
	if (list.precision == -1)
		prec_neg(i, list, ft_strlen_pf(i), buf);
	else if (list.minus == 0)
		prec_pos(i, list, ft_strlen_pf(i), buf);
	else if (list.minus == 1)
		minus_pos(i, list, ft_strlen_pf(i), buf);
}

void		ft_u_up(t_param list, va_list ap, t_buf *buf)
{
	ft_type_u(list,
		ft_itoa_base_ll((unsigned long)va_arg(ap, long int), 10), buf);
}
