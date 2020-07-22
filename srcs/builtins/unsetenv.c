/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:43:04 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/22 18:51:05 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "builtins.h"

static int	unset_from_array(char **arr, int i)
{
	if (i == 0)
	{
		free(arr[i]);
		arr[0] = NULL;
		return (0);
	}
	free(arr[i]);
	arr[i] = arr[i + 1];
	i++;
	while (arr[i])
	{
		arr[i] = arr[i + 1];
		i++;
	}
	return (0);
}

int			btin_unsetenv(t_ltree *pos)
{
	size_t	unused;
	int		j;
	int		i;

	i = 1;
	while (i < pos->ar_c)
	{
		if ((j = find_in_variables(pos->envir, &unused, pos->ar_v[i])) != -1)
			unset_from_array(pos->envir, j);
		i++;
	}
	return (0);
}
