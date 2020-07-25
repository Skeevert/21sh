/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:16:09 by hshawand          #+#    #+#             */
/*   Updated: 2020/07/25 19:49:59 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "edit_line.h"

/*
** History buffer is always static - can't be changed by the user
** can be only scrolled if there are more than MAX_HISTORY lines
** in the @g_hist.cmd array, cmds can be added to the end of the
** @g_hist.cmd array and it can be read
** History can not be saved.
*/

void	init_hist_buff(void)
{
	g_hist.len = MAX_HISTORY;
	g_hist.cmd = (char**)ft_xmalloc(sizeof(char*) * (g_hist.len + 1));
	g_hist.last = -1;
	g_hist.count = 0;
}

/*
** Adding depends on the prompt:
** in quoting or heredoc all the commands separated by "\n"
** are not regarded as commands but mean text (quoting)
** So such text sould not be added to the history
*/

int		add_history(char *cmd)
{
	int		flag;

	flag = 0;
	if (g_hist.last + 1 >= g_hist.len - 1 &&
		g_prompt.prompt_func == main_prompt)
		scroll_hist_buffer(1);
	if (g_prompt.prompt_func == main_prompt)
	{
		g_hist.last++;
		g_hist.cmd[g_hist.last] = ft_strdup(cmd);
	}
	else if (g_prompt.prompt_func != main_prompt &&
		g_prompt.prompt_func != heredoc_prompt)
	{
		flag = (cmd[0] == EOF) ? EOF : 0;
		add_history_eof_cmd(cmd, flag);
	}
	return (0);
}

int		add_history_eof_cmd(char *cmd, int flag)
{
	if (g_hist.cmd[g_hist.last][0] != 0 && flag == 0)
		g_hist.cmd[g_hist.last] =
			ft_strrejoin(g_hist.cmd[g_hist.last], cmd);
	destruct_parser();
	if (flag == EOF)
	{
		g_cmd = (char*)ft_xmalloc(ft_strlen(g_hist.cmd[g_hist.last]) + 2);
		ft_strcpy(g_cmd, g_hist.cmd[g_hist.last]);
		g_cmd = ft_straddsy(g_cmd, EOF);
	}
	else
		g_cmd = ft_strdup(g_hist.cmd[g_hist.last]);
	g_cmd_size = ft_strlen(g_cmd);
	ft_get_techline(g_cmd, &g_techline);
	return (0);
}

/*
** If the coming cmd line is out of the allocated memory, the
** first cmd-line in the history is deleted, all the following
** lines are scrolled so that the last cmd-line in the history
** array becomes empty
*/

int		scroll_hist_buffer(int num)
{
	int		i;

	i = 0;
	while (i < num)
	{
		free(g_hist.cmd[i]);
		g_hist.cmd[i] = NULL;
		i++;
	}
	i = 0;
	while (i < g_hist.len - num)
	{
		g_hist.cmd[i] = g_hist.cmd[i + num];
		i++;
	}
	g_hist.last -= num;
	g_hist.count = g_hist.last + 1;
	return (0);
}
