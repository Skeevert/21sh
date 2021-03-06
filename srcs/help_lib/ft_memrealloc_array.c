/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:19:28 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:19:29 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "libft.h"

void				**ft_memrealloc_array(void ***subj, int len_subj,
						int len_needed)
{
	int				i;
	void			**new;
	void			**old;

	i = 0;
	old = *subj;
	new = (void**)ft_xmalloc(sizeof(void*) * (len_needed + 1));
	while (old[i] && i < len_subj)
	{
		new[i] = old[i];
		i++;
	}
	free(*subj);
	return (new);
}
