/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:19:31 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:19:32 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "libft.h"

char				**ft_realloc_array(char ***subj, int len_subj,
						int len_needed)
{
	int				i;
	char			**new;
	char			**old;

	i = 0;
	old = *subj;
	new = (char**)ft_xmalloc(sizeof(char*) * (len_needed + 1));
	while (old[i] && i < len_subj)
	{
		new[i] = ft_strdup(old[i]);
		i++;
	}
	ft_arrdel(old);
	old = NULL;
	return (new);
}
