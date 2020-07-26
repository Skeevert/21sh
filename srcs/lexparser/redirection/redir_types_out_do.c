/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_types_out_do.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:24:26 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/26 15:15:31 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "lexparser.h"

/*
** Function to do redirectionsin block
*/

int			ft_find_redirection_do(t_ltree *final)
{
	t_list		*fd_list;
	t_fd_redir	*redir;
	int			ret;

	fd_list = final->fd;
	while (fd_list)
	{
		redir = (t_fd_redir *)fd_list->content;
		if (redir->type == GREAT)
			if ((ret = ft_redir_great_do(final, redir)))
				return (ret);
		if (redir->type == DGREAT)
			if ((ret = ft_redir_dgreat_do(final, redir)))
				return (ret);
		if (redir->type == GREATAND)
			if ((ret = ft_redir_greatand_do(final, redir)))
				return (ret);
		if (redir->type == LESS)
			if ((ret = ft_redir_less_do(final, redir)))
				return (ret);
		if (redir->type == LESSAND)
			if ((ret = ft_redir_lessand_do(final, redir)))
				return (ret);
		fd_list = fd_list->next;
	}
	return (0);
}

/*
** Function to do "[n]>word"
*/

int		ft_redir_great_do(t_ltree *final, t_fd_redir *fd)
{
	if ((fd->fd_old = open(fd->name, O_CREAT | O_RDWR | O_TRUNC |
	O_CLOEXEC | O_NDELAY | O_NOCTTY, S_IWUSR)) == -1)
		return (ft_access_check(&fd->name, final, W_OK));
	return (0);
}

/*
** Function to do ">>word" (write to end)
*/

int		ft_redir_dgreat_do(t_ltree *final, t_fd_redir *fd)
{
	if ((fd->fd_old = open(fd->name, O_CREAT | O_RDWR | O_APPEND |
	O_CLOEXEC | O_NDELAY | O_NOCTTY, S_IWUSR)) == -1)
		return (ft_access_check(&fd->name, final, W_OK));
	return (0);
}

/*
** Function to do "[n]>&[m]"
** fcntl used to check access to write in fd
*/

int		ft_redir_greatand_do(t_ltree *final, t_fd_redir *fd)
{
	return (ft_num_or_word_out(&fd->name, fd, final));
}
