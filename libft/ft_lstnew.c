/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:34:28 by rbednar           #+#    #+#             */
/*   Updated: 2019/10/08 16:47:36 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*buf;

	buf = (t_list*)malloc(sizeof(t_list));
	if (!buf)
		return (NULL);
	if (!content)
	{
		buf->content_size = 0;
		buf->content = 0;
	}
	else
	{
		buf->content_size = content_size;
		if (!(buf->content = (void *)malloc(content_size)))
		{
			free(buf);
			return (NULL);
		}
		ft_memcpy(buf->content, content, content_size);
	}
	buf->next = NULL;
	return (buf);
}
