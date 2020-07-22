/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:43:04 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/22 22:44:10 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "builtins.h"

/*
** bash: export: `   fu=ft': not a valid identifier
** erroring for not valig args
*/

int			btin_setenv(t_ltree *pos)
{
	int	i;
	int	len;
	int eq;

	i = 1;
	while (i <= pos->ar_c)
	{
		pos->err_i = i;
		len = ft_strlen(pos->ar_v[pos->err_i]);
		eq = ft_strchri(pos->ar_v[pos->err_i], '=');
		find_assignment_in_vars(pos->ar_v[pos->err_i], 0, eq, len);
		i++;
	}
	return (0);
}
