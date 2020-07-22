/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:37:27 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/22 13:33:35 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "builtins.h"

/*
** Parsser of flags. If non-valid flag finds - returns number of argv.
*/

static int		parse_echo_flags(char **argv, int *echo_flags)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		j = 1;
		flag = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == 'n')
				flag |= ECHO_N;
			else if (argv[i][j] == 'e')
				flag |= ECHO_E;
			else if (argv[i][j] == 'E')
				flag |= ECHO_UP_E;
			else
				return (i);
			j++;
		}
		*echo_flags |= flag;
		i++;
	}
	return (i);
}

static void		write_esc_symb(char c)
{
	if (c == 'a')
		write(STDOUT_FILENO, "\a", 1);
	else if (c == 'b')
		write(STDOUT_FILENO, "\b", 1);
	else if (c == 'f')
		write(STDOUT_FILENO, "\f", 1);
	else if (c == 'n')
		write(STDOUT_FILENO, "\n", 1);
	else if (c == 'r')
		write(STDOUT_FILENO, "\r", 1);
	else if (c == 't')
		write(STDOUT_FILENO, "\t", 1);
	else if (c == 'v')
		write(STDOUT_FILENO, "\v", 1);
	else if (c == 'e')
		write(STDOUT_FILENO, "\033", 1);
}

static void		write_e_echo(char **argv, int i)
{
	int j;

	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '\\')
				write(1, &(argv[i][j]), 1);
			else
			{
				j++;
				write_esc_symb(argv[i][j]);
			}
			j++;
		}
		i++;
		if (argv[i])
			write(1, " ", 1);
	}
}

static void		write_text(char **argv, int i, int *echo_flags)
{
	if ((*echo_flags & ECHO_E) && !(*echo_flags & ECHO_UP_E))
		write_e_echo(argv, i);
	else
	{
		while (argv[i])
		{
			write(1, argv[i], ft_strlen(argv[i]));
			i++;
			if (argv[i])
				write(1, " ", 1);
		}
	}
	if (!(*echo_flags & ECHO_N))
		write(1, "\n", 1);
}

int				btin_echo(t_ltree *pos)
{
	int	echo_flags;
	int	i;

	echo_flags = 0;
	i = parse_echo_flags(pos->ar_v, &echo_flags);
	write_text(pos->ar_v, i, &echo_flags);
	return (0);
}
