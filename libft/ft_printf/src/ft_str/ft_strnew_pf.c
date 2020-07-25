/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <fcraydle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:45:05 by fcraydle          #+#    #+#             */
/*   Updated: 2019/09/20 17:45:05 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void		ft_bzero(void *s, size_t n)
{
	ft_memset_pf(s, '\0', n);
}

static void		*ft_memalloc(size_t size)
{
	void	*new;

	new = NULL;
	if (size != 0)
	{
		if (!(new = (void *)malloc(size)))
			return (NULL);
		ft_bzero(new, size);
	}
	return (new);
}

char			*ft_strnew_pf(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}
