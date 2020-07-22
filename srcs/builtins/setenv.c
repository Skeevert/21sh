/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:43:04 by rbednar           #+#    #+#             */
/*   Updated: 2020/05/29 22:25:23 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"

/*
** bash: export: `   fu=ft': not a valid identifier
** erroring for not valig args
*/

int			btin_setenv(t_ltree *pos)
{
	int	i;
	int	len;

	i = 1;
	while (i <= pos->ar_c)
	{
		pos->err_i = i;
		len = ft_strlen(pos->ar_v[pos->err_i]);
		assignment(pos, len);
		i++;
	}
	return (0);
}
