/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:17:34 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:17:35 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "help_lib.h"

void		*ft_realloc(void *subj, size_t len_subj,
				size_t len, size_t len_needed)
{
	void	*ptr;

	if (!(ptr = malloc(len_needed)))
	{
		write(2, "No space left\n", 15);
		exit(ERR_MALLOC);
	}
	if (len_needed > len_subj)
	{
		ft_memcpy(ptr, subj, len);
		ft_bzero(ptr + len, len_needed - len);
	}
	else
		ft_memcpy(ptr, subj, len_needed);
	free(subj);
	return (ptr);
}
