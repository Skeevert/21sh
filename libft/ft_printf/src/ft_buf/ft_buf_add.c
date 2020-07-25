/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <fcraydle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:40:38 by fcraydle          #+#    #+#             */
/*   Updated: 2019/09/20 17:40:38 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void			ft_print_and_free(int top, char *str)
{
	write(1, str, top + 1);
	while (*str)
	{
		*str = 0;
		str++;
	}
}

void				ft_buf_add_s(t_buf *new, char *str, int flag)
{
	int		putch;
	size_t	len;
	char	*beg;

	len = ft_strlen_pf(str);
	flag == 0 ? beg = str : 0;
	*str == '-' ? str++ : 0;
	new->top + 1 + len >= BUF_SIZE ? ft_print_and_free(new->top, new->buf) : 0;
	new->top + 1 + len >= BUF_SIZE ? new->top = -1 : 0;
	if (len >= BUF_SIZE)
	{
		new->size += len;
		write(1, str, len);
	}
	else
		while (*str)
		{
			putch = ft_write_to_buff(*str, new->buf + 1 + new->top);
			new->size += putch;
			new->top += putch;
			str++;
		}
	flag == 0 ? free(beg) : 0;
}

void				ft_buf_add_ns(t_buf *new, char *str, size_t n, int flag)
{
	int		putch;
	char	*beg;

	if (new->top + 1 + n >= BUF_SIZE)
	{
		new->size += new->top + 1;
		ft_print_and_free(new->top, new->buf);
		new->top = -1;
	}
	flag == 0 ? beg = str : 0;
	if (n >= BUF_SIZE)
	{
		new->size += n;
		write(1, str, n);
	}
	else
		while (*str && n--)
		{
			putch = ft_write_to_buff(*str, new->buf + 1 + new->top);
			new->size += putch;
			new->top += putch;
			str++;
		}
	flag == 0 ? free(beg) : 0;
}

void				ft_buf_add_c(t_buf *new, char c)
{
	if (new->top + 1 >= BUF_SIZE)
	{
		ft_print_and_free(new->top, new->buf);
		new->top = -1;
	}
	new->buf[++new->top] = c;
	new->size++;
}
