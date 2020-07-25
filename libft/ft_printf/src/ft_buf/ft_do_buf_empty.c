/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_buf_empty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <fcraydle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:43:08 by fcraydle          #+#    #+#             */
/*   Updated: 2019/09/20 17:43:08 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int		ft_do_buf_empty(t_buf *buf)
{
	int size;

	size = buf->size;
	write(1, buf->buf, buf->top + 1);
	free(buf->buf);
	buf = NULL;
	return (size);
}
