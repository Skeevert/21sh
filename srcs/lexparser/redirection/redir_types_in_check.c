/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_types_in_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:55:26 by rbednar           #+#    #+#             */
/*   Updated: 2020/08/01 18:47:51 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "lexparser.h"

/*
** Function to detect "[n]<word"
*/

int		ft_redir_less_check(t_ltree *final, int *i)
{
	t_fd_redir	fd;

	fd.name = NULL;
	if (final->l_tline.line[*i] == LTHAN &&
		(final->l_tline.line[*i + 1] != LTHAN &&
		(final->l_tline.line[*i + 1] != AND ||
		final->l_tline.line[*i + 1] == PIPE)))
	{
		fd.type = LESS;
		fd.fd_new = ft_check_n_redir_op(*i, final, STDIN_FILENO);
		ft_null_redir(final, *i, 1);
		(*i)++;
		if ((fd.name = ft_word_to_redir(i, final, FF)) != NULL)
			add_redir_fd(final, &fd);
		else
			return (final->flags |= ERR_OUT | ERR_REDIR << 16);
	}
	free(fd.name);
	return (0);
}

/*
** Function to detect "[n]<<stop_word" here-document
*/

int		ft_redir_dless(t_ltree *final, int *i)
{
	t_fd_redir	fd;

	fd.name = NULL;
	if (final->l_tline.line[*i] == LTHAN && final->l_tline.line[*i + 1] == LTHAN
		&& final->l_cmd[*i + 2] != '-')
	{
		fd.type = DLESS;
		fd.fd_new = ft_check_n_redir_op(*i, final, STDIN_FILENO);
		ft_null_redir(final, *i, 2);
		(*i) += 2;
		if ((fd.name = ft_word_to_redir(i, final, HERE)))
			return (ft_heredoc_form(&fd, &fd.name, final, 0));
		else
			return (final->flags |= ERR_OUT | ERR_REDIR << 16);
	}
	free(fd.name);
	return (0);
}

/*
** Function to detect "[n]<<- stop_word" here-document with TAB delete
*/

int		ft_redir_dless_min(t_ltree *final, int *i)
{
	t_fd_redir	fd;

	fd.name = NULL;
	if (final->l_tline.line[*i] == LTHAN && final->l_tline.line[*i + 1] == LTHAN
		&& final->l_cmd[*i + 2] == '-')
	{
		fd.type = DLESS_MIN;
		fd.fd_new = ft_check_n_redir_op(*i, final, STDIN_FILENO);
		ft_null_redir(final, *i, 3);
		(*i) += 3;
		if ((fd.name = ft_word_to_redir(i, final, HERE)))
			return (ft_heredoc_form(&fd, &fd.name, final, MINUS));
		else
			return (final->flags |= ERR_OUT | ERR_REDIR << 16);
	}
	free(fd.name);
	return (0);
}

/*
** Function to detect "[n]<&[m]" (input from fd or file if)
*/

int		ft_redir_lessand_check(t_ltree *final, int *i)
{
	t_fd_redir	fd;

	fd.name = NULL;
	if (final->l_tline.line[*i] == LTHAN &&
		(final->l_tline.line[*i + 1] == AND))
	{
		fd.type = LESSAND;
		fd.fd_new = ft_check_n_redir_op(*i, final, STDIN_FILENO);
		ft_null_redir(final, *i, 2);
		(*i) += 2;
		if ((fd.name = ft_word_to_redir(i, final, FF)) != NULL)
			add_redir_fd(final, &fd);
		else
			return (final->flags |= ERR_OUT | ERR_REDIR << 16);
	}
	free(fd.name);
	return (0);
}

int		ft_heredoc_form(t_fd_redir *fd_open, char **f_name, t_ltree *final,
		int flag)
{
	if (g_prompt.prompt_func == main_prompt)
	{
		if (ft_tmpfile(TMPL, &fd_open->fd_old) == -1)
			return (final->flags |= ERR_OUT | ERR_TMPFILE << 16);
		add_redir_fd(final, fd_open);
		g_heredoc.stop.stop_w = *f_name;
		g_heredoc.stop.fd = fd_open->fd_old;
		g_heredoc.stop.flag = flag;
		ft_add_list_to_end(&(g_heredoc.list),
			ft_lstnew(&g_heredoc.stop, sizeof(t_stop)));
	}
	return (0);
}
