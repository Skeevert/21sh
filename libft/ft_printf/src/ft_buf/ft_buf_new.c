/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <fcraydle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:42:33 by fcraydle          #+#    #+#             */
/*   Updated: 2019/09/20 17:42:33 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

t_buf				*ft_buf_new(t_buf *new)
{
	new->size = 0;
	new->top = -1;
	new->err = 0;
	if (!(new->buf = ft_strnew_pf(BUF_SIZE)))
		return (NULL);
	return (new);
}
