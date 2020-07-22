/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:37:46 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/22 13:42:54 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "builtins.h"

static int		argument_check(t_ltree *pos)
{
	int	i;

	i = 0;
	if (pos->ar_v[1][0] == '+' || pos->ar_v[1][0] == '-')
		i++;
	while (pos->ar_v[1][i])
	{
		if (ft_isdigit(pos->ar_v[1][i]))
			i++;
		else
			break ;
	}
	if (pos->ar_v[1][i] == '\0')
		return (0);
	return (1);
}

int				btin_exit(t_ltree *pos)
{
	int	exit_status;

	if (pos->ar_c == 1)
		exit_status = 0;
	else if (pos->ar_c > 2 && !argument_check(pos))
	{
		ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
		return (1);
	}
	else
	{
		if (!argument_check(pos) && pos->ar_c == 2)
			exit_status = ft_atoi(pos->ar_v[1]);
		else
		{
			ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
			ft_putstr_fd(pos->ar_v[1], STDERR_FILENO);
			ft_putendl_fd(": numeric argument required", STDERR_FILENO);
			exit_status = 2;
		}
	}
	ft_putendl_fd("exit", STDOUT_FILENO);
	destruct_globals();
	exit(exit_status & 0xFF);
}
