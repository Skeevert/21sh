/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:08:20 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/27 01:11:34 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "edit_line.h"

int		signals_define(int from)
{
	if (from == 1)
	{
		signal(SIGINT, signal_ctrl_c_readline);
		signal(SIGWINCH, signal_screen);
		signal(SIGCONT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);
	}
	else if (from == 2)
	{
		signal(SIGINT, signal_ctrl_c_exec);
		signal(SIGTSTP, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGCONT, SIG_IGN);
	}
	return (0);
}

void	signal_ctrl_c_readline(int sig)
{
	sig = sig ? sig : sig;
	ft_putchar_fd('\n', 1);
	g_prompt.prompt_func = main_prompt;
	g_prompt.prompt_func();
	bzero_readline();
}

void	signal_ctrl_c_exec(int sig)
{
	sig = sig ? sig : sig;
	ft_putchar_fd('\n', 1);
	g_prompt.prompt_func = main_prompt;
	bzero_readline();
}

void	signal_screen(int sig)
{
	int				i;

	sig = sig ? sig : sig;
	put_cursor("ch", 0, 0);
	put_termcap("cd");
	init_wind_size();
	g_readline.pos = 0;
	g_readline.pos_x = g_prompt.prompt_len;
	g_readline.pos_y = 0;
	g_readline.str_num = 1;
	g_prompt.prompt_func();
	i = -1;
	while (g_readline.cmd[++i])
	{
		g_readline.pos++;
		front_insert_char(g_readline.cmd[i]);
	}
}
