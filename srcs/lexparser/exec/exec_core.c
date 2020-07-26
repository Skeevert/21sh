/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:50:54 by hshawand          #+#    #+#             */
/*   Updated: 2020/07/26 16:18:41 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "lexparser.h"

/*
** Delete pipe process and simplify, leaving only dealing with EXECPATH
*/

int		std_save(int mode)
{
	static int	save[3];

	if (!mode)
	{
		save[0] = dup(STDIN_FILENO);
		save[1] = dup(STDOUT_FILENO);
		save[2] = dup(STDERR_FILENO);
	}
	else
	{
		dup2(save[0], 0);
		dup2(save[1], 1);
		dup2(save[2], 2);
	}
	return (0);
}

int		fork_and_exec(t_ltree *pos, char *path, pid_t *child_pid)
{
	*child_pid = fork();
	if (!*child_pid)
	{
		if (execve(path, pos->ar_v, pos->envir) == -1)
			exit(-1);
	}
	else if (*child_pid < 0)
		return (exec_clean(&path, pos, -2));
	wait(child_pid);
	return (0);
}

int		exec_core(t_ltree *pos)
{
	pid_t			child_pid;
	int				ret;
	char			*path;
	static int		pipe_prev;
	static int		pipe_next[2];

	path = NULL;
	child_pid = 0;
	ret = 0;
	if (ft_builtins_check(pos, 0) == -1 && !(path = path_init(pos, &path)))
		ret = -2;
	(pos->flags & PIPED_IN) ? (pipe_prev = pipe_next[0]) : 0;
	if ((pos->flags & PIPED_OUT) && pipe(pipe_next) == -1)
		ret = -1;
	fd_list_process(pos, 0);
	(pos->flags & PIPED_OUT) ? dup2(pipe_next[1], 1) : 0;
	(pos->flags & PIPED_IN) ? dup2(pipe_prev, 0) : 0;
	if (ft_builtins_check(pos, 1) == -1)
		!ret ? fork_and_exec(pos, path, &child_pid) : 0;
	(pos->flags & PIPED_OUT) ? close(pipe_next[1]) : 0;
	(pos->flags & PIPED_IN) ? close(pipe_prev) : 0;
	fd_list_process(pos, 1);
	return (exec_clean(&path, pos, WIFEXITED(child_pid) && !ret ?
		WEXITSTATUS(child_pid) : (ret)));
}
