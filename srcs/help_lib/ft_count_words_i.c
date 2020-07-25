/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:19:01 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:19:02 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "help_lib.h"

size_t	ft_count_words_i(char const *s, char c, size_t len)
{
	size_t	k;
	size_t	i;

	k = 0;
	i = 0;
	while (i < len)
	{
		if (s[i] != c && (s[i + 1] == c || i + 1 == len))
			k++;
		i++;
	}
	return (k);
}
