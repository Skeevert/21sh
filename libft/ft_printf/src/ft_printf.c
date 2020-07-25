/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <fcraydle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 12:16:21 by fcraydle          #+#    #+#             */
/*   Updated: 2019/09/19 18:29:42 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		get_colours(char **str, t_buf *buf)
{
	*str = ft_colours(*str + 1, buf);
	**str != '}' ? ft_buf_add_c(buf, **str) : NULL;
}

int				ft_printf(char *str, ...)
{
	va_list		ap;
	t_buf		buf;
	t_param		list;
	int			res;

	va_start(ap, str);
	ft_buf_new(&buf);
	ft_param_nul(&list);
	while (*str)
	{
		if (*(str++) == '%')
			ft_percent(ap, &str, list, &buf);
		else if (*(--str) == '{')
			get_colours(&str, &buf);
		else
			ft_buf_add_c(&buf, *str);
		*str ? str++ : NULL;
		buf.err == 1 ? free(buf.buf) : 0;
		if (buf.err == 1)
			return (-1);
	}
	res = ft_do_buf_empty(&buf);
	va_end(ap);
	return (res);
}
