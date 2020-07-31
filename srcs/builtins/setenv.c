/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:43:04 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/31 22:42:26 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "builtins.h"

/*
** bash: setenv: `   fu=ft': not a valid identifier
** erroring for not valig args
*/

int			btin_setenv(t_ltree *pos)
{
	int		i;
	int		len;
	int		eq;
	char	*find;

	i = 1;
	while (i < pos->ar_c)
	{
		pos->err_i = i;
		len = ft_strlen(pos->ar_v[pos->err_i]);
		eq = ft_strchri(pos->ar_v[pos->err_i], '=');
		find = ft_strndup(pos->ar_v[pos->err_i], eq);
		find_assignment_in_vars(pos->ar_v[pos->err_i], 0, eq, len);
		eq = variable_search(&len, find);
		g_envi[eq][0] |= ENV_VIS;
		free(find);
		i++;
	}
	return (0);
}
