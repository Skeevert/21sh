/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:41:07 by fcraydle          #+#    #+#             */
/*   Updated: 2019/10/15 20:50:12 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void			prec_neg(char *str, t_param list, t_buf *buf)
{
	int tmp;

	tmp = ft_strlen_pf(str);
	if (list.minus == 0 && list.zero == 1 && list.width - list.hasht > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.width - list.hasht - tmp, '0'), 0);
	else if (list.minus == 0 && list.zero == 0 && list.width - list.hasht > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.width - list.hasht - tmp, ' '), 0);
	list.hasht == 1 ? ft_buf_add_c(buf, '0') : NULL;
	ft_buf_add_s(buf, str, 0);
	if (list.minus == 1 && list.width - list.hasht > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.width - list.hasht - tmp, ' '), 0);
}

static void			minus_neg(char *str, t_param list, t_buf *buf, int tmp)
{
	if (list.width > list.precision && list.width > tmp && list.zero == 1 &&
														list.precision <= -1)
		ft_buf_add_s(buf, ft_memnew_pf(list.width -
			(list.precision > tmp ? list.precision : tmp) -
				(list.hasht == 1 && list.precision <= tmp), '0'), 0);
	else if (list.width > list.precision && list.width > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.width -
			(list.precision > tmp ? list.precision : tmp) -
				(list.hasht == 1 && list.precision <= tmp), ' '), 0);
	if (tmp >= list.precision && list.hasht == 1)
		ft_buf_add_c(buf, '0');
	if (list.precision > tmp)
		ft_buf_add_s(buf, ft_memnew_pf(list.precision - tmp, '0'), 0);
	tmp != 0 ? ft_buf_add_s(buf, str, 0) : 0;
}

static void			prec_pos(char *str, t_param list, t_buf *buf)
{
	int tmp;

	tmp = ft_strlen_pf(str);
	if (list.minus == 0)
		minus_neg(str, list, buf, tmp);
	else
	{
		if (tmp >= list.precision && list.hasht == 1)
			ft_buf_add_c(buf, '0');
		if (list.precision > tmp)
			ft_buf_add_s(buf, ft_memnew_pf(list.precision - tmp, '0'), 0);
		tmp != 0 ? ft_buf_add_s(buf, str, 0) : 0;
		if (list.width > list.precision && list.width > tmp)
			ft_buf_add_s(buf, ft_memnew_pf(list.width -
				(list.precision > tmp ? list.precision : tmp) -
					(list.hasht == 1 && list.precision <= tmp), ' '), 0);
	}
}

static void			ft_type_o(t_param list, char *str, t_buf *buf)
{
	if (*str != '0')
	{
		if (list.precision == -1)
			prec_neg(str, list, buf);
		else
			prec_pos(str, list, buf);
	}
	else
	{
		if (list.precision == -1)
			ft_prec_neg_null(str, list, buf);
		else
			ft_prec_pos_null(list, buf);
	}
}

void				ft_o(t_param list, va_list ap, t_buf *buf)
{
	if (list.length == 0)
		ft_type_o(list,
				ft_itoa_base_ll((unsigned int)va_arg(ap, int), 8), buf);
	else if (list.length == 'l')
		ft_type_o(list,
				ft_itoa_base_ll((unsigned long)va_arg(ap, int), 8), buf);
	else if (list.length == 'l' + 'l')
		ft_type_o(list,
		ft_itoa_base_ll((unsigned long long)va_arg(ap, long long), 8), buf);
	else if (list.length == 'h')
		ft_type_o(list,
				ft_itoa_base_ll((unsigned short)va_arg(ap, int), 8), buf);
	else if (list.length == 'h' + 'h')
		ft_type_o(list,
				ft_itoa_base_ll((unsigned char)va_arg(ap, int), 8), buf);
	else if (list.length == 'j')
		ft_type_o(list,
				ft_itoa_base_ll((uintmax_t)va_arg(ap, uintmax_t), 8), buf);
	else if (list.length == 'z')
		ft_type_o(list, ft_itoa_base_ll((size_t)va_arg(ap, size_t), 8), buf);
}
