/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 20:30:26 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/22 20:30:28 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "libft.h"

void			ft_arrshift(char **arr, int size, int shift)
{
	char		**buff;
	int			i;

	if (arr == (char**)NULL)
		return ;
	buff = (char**)ft_xmalloc(sizeof(char*) * (size + 1));
	ft_memcpy(buff, arr, sizeof(char*) * size);
	if (shift < 0)
	{
		i = shift - 1;
		while (++i)
			free(arr[i]);
	}
	ft_memcpy(arr + shift, buff, sizeof(char*) * (size - shift));
	i = 0;
	while (i < shift)
	{
		arr[i] = (char*)NULL;
		i++;
	}
	free(buff);
}
