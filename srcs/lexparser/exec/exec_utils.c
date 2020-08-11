/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:52:35 by hshawand          #+#    #+#             */
/*   Updated: 2020/08/11 21:36:06 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "lexparser.h"
#include "builtins_list.h"

/*
** So, let's talk about pipes:
** 1) If only PIPED_OUT -- create pipe
** 2) If only PIPED_IN -- delete pipe
*/

/*
** consider changing architecture to... well, something else
*/

int		exec_clean(char **path, t_ltree *pos, int exit_status)
{
	if (exit_status == -2)
	{
		if (pos->err_i == ERR_ISDIR)
			errno(ERR_CMDEXEC, ERR_ISDIR, *pos->ar_v);
		else if (pos->err_i == ERR_CMDEXEC)
			errno(ERR_CMDEXEC, ERR_CMDEXEC, *pos->ar_v);
		else if (pos->err_i == ERR_NOFILEDIR)
			errno(ERR_CMDNOTFOUND, ERR_NOFILEDIR, *pos->ar_v);
		else
			errno(ERR_CMDNOTFOUND, ERR_NOCMD, *pos->ar_v);
	}
	else if (exit_status == -1)
		errno(ERR_PIPE, ERR_PIPE, *pos->ar_v);
	if (path && *path)
		free(*path);
	return (exit_status);
}

/*
** Check if programm to start is buildin and if it is - start builtins
*/

int		ft_builtins_check(t_ltree *pos, int flag)
{
	int	i;
	int	exit;

	i = 0;
	while (g_builtins[i] && pos->ar_v[0])
	{
		if (!ft_strcmp(pos->ar_v[0], g_builtins[i]))
		{
			if (flag)
			{
				if (!(pos->flags & PIPED_IN) && !(pos->flags & PIPED_OUT))
					fd_list_process(pos, 0);
				exit = g_builtins_func[i](pos);
				var_exit_status(exit);
			}
			return (i);
		}
		i++;
	}
	return (-1);
}

int		fd_list_process(t_ltree *pos, int mode)
{
	t_list		*fd_list;
	t_fd_redir	*redir;

	if (!mode)
	{
		fd_list = pos->fd;
		while (fd_list)
		{
			redir = (t_fd_redir *)fd_list->content;
			if (redir->fd_old != CLOSE)
				dup2(redir->fd_old, redir->fd_new);
			else
				close(redir->fd_new);
			fd_list = fd_list->next;
		}
	}
	else
		std_save(1);
	return (0);
}
