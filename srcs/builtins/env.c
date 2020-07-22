/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:57:49 by rbednar           #+#    #+#             */
/*   Updated: 2020/05/29 22:22:09 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"

int			btin_env(t_ltree *pos)
{
	char	**list;
	int		max;

	list = pos->envir;
	max = -1;
	while (list[++max])
		ft_putendl_fd(list[max], STDOUT_FILENO);
	return (0);
}
