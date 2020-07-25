/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edition_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:33:18 by hshawand          #+#    #+#             */
/*   Updated: 2020/07/25 17:33:19 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "edit_line.h"

void	init_readline(void)
{
	g_readline.cmd = (char *)ft_xmalloc(CMD_SIZE + 1);
	g_readline.cmd_len = 0;
	g_readline.pos = 0;
	g_readline.pos_x = g_prompt.prompt_len;
	g_readline.pos_y = 0;
	g_readline.str_num = 1;
	g_readline.cmd_buff_len = CMD_SIZE + 1;
	g_readline.flag = 0;
}

void	bzero_readline(void)
{
	ft_bzero(g_readline.cmd, g_readline.cmd_buff_len);
	g_readline.cmd_len = 0;
	g_readline.pos = 0;
	g_readline.pos_x = g_prompt.prompt_len;
	g_readline.pos_y = 0;
	g_readline.str_num = 1;
	(!(g_readline.flag & PROMPTLEN_ZERO)) ? g_readline.flag = 0 : 0;
}

void	init_wind_size(void)
{
	if (ioctl(1, TIOCGWINSZ, &g_winsize))
	{
		errno(ERR_TERMINAL, 0, NULL);
		destruct_globals();
		exit(ERR_TERMINAL);
	}
	if (g_winsize.ws_col == 0)
		g_winsize.ws_col = 80;
}

void	realloc_readline_cmd(void)
{
	g_readline.cmd = (char *)ft_realloc(g_readline.cmd,
		g_readline.cmd_len, g_readline.cmd_buff_len,
		g_readline.cmd_buff_len + CMD_SIZE);
	g_readline.cmd_buff_len += CMD_SIZE;
}
