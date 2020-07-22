/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:43:04 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/22 22:51:28 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "builtins.h"

int			btin_unsetenv(t_ltree *pos)
{
	int	unused;
	int		j;
	int		i;

	i = 1;
	while (i < pos->ar_c)
	{
		if ((j = variable_search(&unused, pos->ar_v[i])) != -1 &&
			g_envi[j][0] & ENV_VIS && !(g_envi[j][0] & READONLY))
			unset_from_array(&g_envi, j);
		i++;
	}
	return (0);
}
