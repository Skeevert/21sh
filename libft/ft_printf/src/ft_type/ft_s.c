/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:47:59 by fcraydle          #+#    #+#             */
/*   Updated: 2019/10/15 19:33:31 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void		minus_neg(t_param list, char *s, int tmp, t_buf *buf)
{
	if (list.width > (tmp < list.precision
								? tmp : list.precision) && list.zero == 1)
		ft_buf_add_s(buf, ft_memnew_pf(list.width -
		(tmp < list.precision ? tmp : list.precision) -
		(tmp == 0 ? list.precision : 0), '0'), 1);
	else if (list.width > (tmp < list.precision ?
										tmp : list.precision) && s != NULL)
		ft_buf_add_s(buf, ft_memnew_pf(list.width -
		(tmp < list.precision ? tmp : list.precision), ' '), 1);
	if (s != NULL)
		ft_buf_add_ns(buf, s, tmp < list.precision ? tmp : list.precision, 1);
	else
		ft_buf_add_ns(buf, "(null)", list.precision, 1);
}

static void		prec_pos(t_param list, char *s, int tmp, t_buf *buf)
{
	if (list.minus == 0)
		minus_neg(list, s, tmp, buf);
	else
	{
		if (s != NULL)
			ft_buf_add_ns(buf, s, tmp < list.precision ?
													tmp : list.precision, 1);
		else
			ft_buf_add_ns(buf, "(null)", list.precision, 1);
		if (list.width >
			(tmp < list.precision ? tmp : list.precision) && list.zero == 1)
			ft_buf_add_s(buf, ft_memnew_pf(list.width - \
			(tmp < list.precision ? tmp : list.precision) \
			- (tmp == 0 ? list.precision : 0), '0'), 1);
		else if (list.width > (tmp < list.precision ?
										tmp : list.precision) && s != NULL)
			ft_buf_add_s(buf, ft_memnew_pf(list.width - \
			(tmp < list.precision ? tmp : list.precision), ' '), 1);
	}
}

static void		ft_kostil(t_param *list, char **s, int tmp, t_buf **buf)
{
	char *fr;

	if (list->width > tmp && list->zero == 0 && *s != NULL)
	{
		ft_buf_add_s(*buf, fr = ft_memnew_pf(list->width - tmp, ' '), 1);
		free(fr);
	}
	else if (list->width > tmp && list->zero == 1)
	{
		ft_buf_add_s(*buf, fr = ft_memnew_pf(list->width - tmp, '0'), 1);
		free(fr);
	}
}

static void		prec_neg(t_param list, char *s, int tmp, t_buf *buf)
{
	if (list.minus == 0)
	{
		if (list.width > tmp && list.zero == 0 && s != NULL)
			ft_buf_add_s(buf, ft_memnew_pf(list.width - tmp, ' '), 1);
		else if (list.width > tmp && list.zero == 1)
			ft_buf_add_s(buf, ft_memnew_pf(list.width - tmp, '0'), 1);
		if (s != NULL)
			ft_buf_add_s(buf, s, 1);
		else
			ft_buf_add_s(buf, "(null)", 1);
	}
	else
	{
		if (s != NULL)
			ft_buf_add_s(buf, s, 1);
		else
			ft_buf_add_s(buf, "(null)", 1);
		ft_kostil(&list, &s, tmp, &buf);
	}
}

void			ft_s(t_param list, char *s, t_buf *buf)
{
	int	tmp;

	tmp = ft_strlen_pf(s);
	if (list.precision > -1)
		prec_pos(list, s, tmp, buf);
	else
		prec_neg(list, s, tmp, buf);
}
