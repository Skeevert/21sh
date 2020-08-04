/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_core.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:50:54 by hshawand          #+#    #+#             */
/*   Updated: 2020/08/04 04:06:30 by rbednar          ###   ########.fr       */
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
		dup2(save[0], STDIN_FILENO);
		dup2(save[1], STDOUT_FILENO);
		dup2(save[2], STDERR_FILENO);
	}
	return (0);
}

int		kill_pipe(t_ltree *pos, t_stack **stack, int *status)
{
	if (!(pos->flags & PIPED_OUT) && (pos->flags & PIPED_IN))
	{
		if (*stack)
		{
			while ((*stack)->data != 0)
			{
				waitpid((*stack)->data, status, 0);
				ft_pop_stack(stack);
			}
			ft_clear_stack(stack);
			signal(SIGTTIN, SIG_DFL);
		}
	}
	return (0);
}

void	fork_func(t_ltree *pos, char *path, int fd[3])
{
	if ((pos->flags & PIPED_OUT) && !(pos->flags & PIPED_IN))
	{
		close(fd[1]);
		dup2(fd[2], STDOUT_FILENO);
	}
	else if ((pos->flags & PIPED_IN) && !(pos->flags & PIPED_OUT))
	{
		close(fd[2]);
		dup2(fd[0], STDIN_FILENO);
	}
	else if ((pos->flags & PIPED_IN) && (pos->flags & PIPED_OUT))
	{
		close(fd[1]);
		dup2(fd[2], STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
	}
	fd_list_process(pos, 0);
	if (execve(path, pos->ar_v, pos->envir) == -1)
		_exit(-1);
}

int		fork_and_exec(t_ltree *pos, char *path, pid_t *child_pid, int fd[3])
{
	static t_stack	*stack;
	int				status;

	status = 0;
	if (!(*child_pid = fork()))
		fork_func(pos, path, fd);
	else if (*child_pid < 0)
		return (exec_clean(&path, pos, -2));
	if (pos->flags & PIPED_OUT)
		close(fd[2]);
	if ((pos->flags & PIPED_OUT) && (pos->flags & PIPED_IN))
		close(fd[1]);
	if (pos->flags & PIPED_IN)
		close(fd[0]);
	if (!(pos->flags & PIPED_OUT))
		waitpid(*child_pid, &status, 0) != *child_pid ? status = -1 : 0;
	else
	{
		if (!stack)
			stack = ft_init_stack();
		ft_push_stack(&stack, *child_pid);
	}
	kill_pipe(pos, &stack, &status);
	*child_pid = status;
	return (0);
}

int		exec_core(t_ltree *pos, int ret)
{
	pid_t			child_pid;
	char			*path;
	static int		pipe_next[2];
	static int		fd[3];

	path = NULL;
	child_pid = 0;
	ret = 0;
	if (ft_builtins_check(pos, 0) == -1 && !(path = path_init(pos, &path)))
		ret = -2;
	if (pos->flags & PIPED_IN)
		(fd[0]= pipe_next[0]);
	if ((pos->flags & PIPED_OUT) && pipe(pipe_next) == -1)
		ret = -1;
	std_save(0);
	fd[1] = pipe_next[0];
	fd[2] = pipe_next[1];
	if (ft_builtins_check(pos, 1) == -1)
		!ret ? fork_and_exec(pos, path, &child_pid, fd) : 0;
	fd_list_process(pos, 1);
	return (exec_clean(&path, pos, (WIFEXITED(child_pid) && !ret) ?
		WEXITSTATUS(child_pid) : ret));
}
