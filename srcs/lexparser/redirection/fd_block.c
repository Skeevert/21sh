/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_block.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:55:22 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/26 18:18:22 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "lexparser.h"

/*
** Function to add redirection rule to block before execve
** uses address of block, fd in and out and type of redirection input/output
*/

int		add_redir_fd(t_ltree *final, t_fd_redir *redir)
{
	t_list		*new;
	t_fd_redir	*fd_work;

	new = (t_list *)ft_xmalloc(sizeof(t_list));
	new->content = (void *)ft_xmalloc(sizeof(t_fd_redir));
	new->content_size = sizeof(t_fd_redir);
	fd_work = (t_fd_redir *)new->content;
	fd_work->fd_new = redir->fd_new;
	fd_work->fd_old = redir->fd_old;
	fd_work->type = redir->type;
	fd_work->name = ft_strdup(redir->name);
	ft_add_list_to_end(&(final->fd), new);
	return (0);
}

/*
** Must be used to check if is IO_NUMBER before redirection operator or not
** std is standart input or output
*/

int		ft_check_n_redir_op(int i, t_ltree *final, int std)
{
	char	*find;
	int		count;
	int		ret;

	find = ft_word_to_redir(&i, final, REW);
	count = 0;
	if (find)
	{
		while (find[count])
		{
			if (find[count] == TEXT)
			{
				free(find);
				return (std);
			}
			count++;
		}
		ret = ft_atoi(find);
		free(find);
		return (ret);
	}
	return (std);
}

/*
** Must be used to check if is IO_NUMBER after redirection operator or not
** std is standart input or output
*/

int		ft_check_redir_op_n(char *find, int std)
{
	char	*buf;

	buf = find;
	if (buf)
	{
		while (*buf)
		{
			if (*buf == TEXT || !(ft_isdigit(*find)))
				return (std);
			buf++;
		}
		return (ft_atoi(find));
	}
	return (std);
}

/*
** Must be used to check if is IO_NUMBER after redirection operator or not
** add fd or filename's fd
*/

int		ft_num_or_word_out(char **f_name, t_fd_redir *fd_open,
						t_ltree *final)
{
	int		fd_ret;

	if ((fd_ret = ft_check_redir_op_n(*f_name, -1)) == -1)
	{
		if (!(ft_strcmp(*f_name, "-")))
			fd_open->fd_old = CLOSE;
		else if ((fd_open->fd_old = open(*f_name, O_CREAT | O_WRONLY | O_TRUNC |
			O_CLOEXEC | O_SYNC | O_NOCTTY, 00666)) == -1)
			return (ft_access_check(f_name, final, W_OK));
	}
	else if ((final->err = ft_strdup(*f_name)) != NULL)
	{
		if (((fd_open->fd_old = fcntl(fd_ret, F_GETFL)) & O_ACCMODE)
			!= O_WRONLY && (fd_open->fd_old & O_ACCMODE) != O_RDWR)
			return (final->flags |= ERR_IN | ERR_R | ERR_FD << 16);
		else
			fd_open->fd_old = fd_ret;
	}
	return (0);
}

int		ft_num_or_word_in(char **f_name, t_fd_redir *fd_open,
							t_ltree *final)
{
	int		fd_ret;

	if ((fd_ret = ft_check_redir_op_n(*f_name, -1)) == -1)
	{
		if (!(ft_strcmp(*f_name, "-")))
			fd_open->fd_old = CLOSE;
		else if ((fd_open->fd_old = open(*f_name, O_RDONLY |
			O_CLOEXEC | O_SYNC | O_NOCTTY)) == -1)
			return (ft_access_check(f_name, final, R_OK));
	}
	else if ((final->err = ft_strdup(*f_name)) != NULL)
	{
		if (((fd_open->fd_old = fcntl(fd_ret, F_GETFL)) & O_ACCMODE)
			!= O_RDONLY && (fd_open->fd_old & O_ACCMODE) != O_RDWR)
			return (final->flags |= ERR_IN | ERR_R | ERR_FD << 16);
		else
			fd_open->fd_old = fd_ret;
	}
	return (0);
}
