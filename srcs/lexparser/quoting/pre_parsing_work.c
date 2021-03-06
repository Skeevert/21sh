/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing_work.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:49:13 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 15:50:16 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "lexparser.h"

/*
** Simle to remove unused number (num_sym) of symbols by moving end of g_cmd
** g_techline.line and resizing g_cmd_size and g_techline.len.
*/

int		ft_reglue(int *i, int num, t_ltree *sub)
{
	size_t	z;
	size_t	size;

	ft_memmove(&(sub->l_cmd[*i]), &(sub->l_cmd[*i + num]),
	sub->l_tline.len - (*i + num - 1));
	ft_memmove(&(sub->l_tline.line[*i]), &(sub->l_tline.line[*i + num]),
	sub->l_tline.len - (*i + num - 1));
	sub->l_tline.len -= num;
	sub->end -= num;
	z = sub->l_tline.len;
	size = z + num;
	while (++z <= size)
	{
		sub->l_cmd[z] = '\0';
		sub->l_tline.line[z] = '\0';
	}
	return (0);
}

int		pre_parsing_back(int *i, t_ltree *sub)
{
	char	*end;

	end = sub->l_tline.line;
	if (end[*i] == BSLASH && end[*i + 1] == ENTER)
		ft_reglue(i, 2, sub);
	if (end[*i] == BSLASH && end[*i + 1] == BSLASH)
	{
		ft_reglue(i, 1, sub);
		(*i)++;
	}
	if (end[*i] == BSLASH)
		ft_reglue(i, 1, sub);
	return (0);
}

int		pre_parsing_andor_pipe(int *i, t_ltree *sub)
{
	char	*end;

	end = sub->l_tline.line;
	if ((end[*i] == PIPE && end[*i + 1] == PIPE) ||
		(end[*i] == AND && end[*i + 1] == AND) ||
		end[*i] == PIPE)
	{
		if (end[*i] == PIPE && end[*i + 1] != PIPE)
			*i += 1;
		else
			*i += 2;
		while (end[*i] == SPACE)
			(*i)++;
		if (end[*i] == ENTER)
		{
			end[*i] = SPACE;
			sub->l_cmd[*i] = ' ';
		}
	}
	return (0);
}

int		pre_parsing_squote(int *i, t_ltree *sub)
{
	char	*end;

	end = sub->l_tline.line;
	if (end[*i] == DOLLAR && end[*i + 1] == SQUOTE)
	{
		ft_reglue(i, 2, sub);
		pre_parsing_ansi(i, sub);
		ft_reglue(i, 1, sub);
	}
	else if (end[*i] == SQUOTE)
	{
		ft_reglue(i, 1, sub);
		while (end[*i] != SQUOTE)
			(*i)++;
		ft_reglue(i, 1, sub);
	}
	pre_parsing_andor_pipe(i, sub);
	pre_parsing_back(i, sub);
	return (0);
}

/*
** This function and subfunctions needs to cut and glue line before parsing.
** It shall be done by POSIX to remove \, "" and '' from line
*/

int		pre_parsing_cut_glue(t_ltree *sub)
{
	char	*end;
	int		i;

	i = 0;
	end = sub->l_tline.line;
	while ((size_t)i < sub->l_tline.len)
	{
		if (end[i] == DQUOTE)
		{
			ft_reglue(&i, 1, sub);
			while (end[i] != DQUOTE)
			{
				end[i] == SPACE ? end[i] = GLUE : 0;
				pre_parsing_back(&i, sub);
				i++;
			}
			ft_reglue(&i, 1, sub);
		}
		else
			pre_parsing_squote(&i, sub);
		if (end[i] == ENTER)
			ft_reglue(&i, 1, sub);
		i++;
	}
	return (0);
}
