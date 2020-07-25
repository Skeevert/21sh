/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:16:52 by hshawand          #+#    #+#             */
/*   Updated: 2020/07/25 17:24:06 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "edit_line.h"

int		add_char(char c, int flag)
{
	if (g_readline.cmd_len >= g_readline.cmd_buff_len - 1)
	{
		g_readline.cmd = (char *)ft_realloc(g_readline.cmd, g_readline.cmd_len,
			g_readline.cmd_buff_len,
			g_readline.cmd_buff_len + CMD_SIZE);
		g_readline.cmd_buff_len += CMD_SIZE;
	}
	if (flag == 'u')
		undo(0);
	g_readline.cmd_len++;
	if (g_readline.cmd_len + 1 < 0 || g_readline.cmd_buff_len + 1 < 0)
		return (EXIT);
	insert_char(c);
	return (0);
}

int		insert_char(char c)
{
	char	*buff;
	char	*str;

	if (g_readline.cmd[g_readline.pos])
	{
		str = g_readline.cmd + g_readline.pos;
		buff = (char *)ft_xmalloc(ft_strlen(g_readline.cmd + g_readline.pos)
			+ 1);
		ft_strcpy(buff, str);
		ft_strcpy(str + 1, buff);
		free(buff);
		g_readline.cmd[g_readline.pos] = c;
		put_termcap("cd");
		front_insert_char(g_readline.cmd[g_readline.pos]);
		g_readline.pos++;
		setjmp_cursor(&g_readline.pos, &g_readline.pos_x, &g_readline.pos_y, 1);
		front_insert_till_end(g_readline.pos_y + 1);
	}
	else
	{
		g_readline.cmd[g_readline.pos] = c;
		g_readline.pos++;
		front_insert_char(c);
	}
	return (0);
}

int		front_insert_char(char c)
{
	write(STDOUT_FILENO, &c, 1);
	if (c == '\n')
	{
		return (front_insert_newline(&g_readline.pos_x, &g_readline.pos_y,
				&g_readline.str_num, &g_readline.flag));
	}
	if (g_readline.pos_x == g_winsize.ws_col - 1)
	{
		put_termcap("sf");
		g_readline.pos_x = 0;
		g_readline.pos_y++;
		g_readline.flag |= NEW_LINE_TE;
		return (0);
	}
	if (g_readline.pos_x == 0 && !(g_readline.flag & NEW_LINE_SY))
		g_readline.str_num++;
	else if (g_readline.pos_x == 0 && (g_readline.flag & NEW_LINE_SY))
		g_readline.flag &= ~(NEW_LINE_SY);
	if (g_readline.flag & PROMPTLEN_ZERO)
		g_readline.flag &= ~(PROMPTLEN_ZERO);
	g_readline.pos_x++;
	return (0);
}

int		front_insert_newline(int *pos_x, int *pos_y,
			int *str_num, int *flag)
{
	*pos_x = 0;
	(*pos_y)++;
	(*str_num)++;
	if (*flag & NEW_LINE_TE)
	{
		(*str_num)++;
		*flag &= ~(NEW_LINE_TE);
	}
	*flag |= NEW_LINE_SY;
	return (0);
}

int		front_insert_till_end(int str_num_print)
{
	int		pos_back;
	int		pos_x_back;
	int		pos_y_back;

	if (g_readline.pos > 0 && g_readline.pos_x == 0 &&
			g_readline.cmd[g_readline.pos - 1] != '\n')
		g_readline.str_num = str_num_print - 1;
	else
		g_readline.str_num = str_num_print;
	while (g_readline.pos < g_readline.cmd_len)
	{
		front_insert_char(g_readline.cmd[g_readline.pos]);
		g_readline.pos++;
	}
	setjmp_cursor(&pos_back, &pos_x_back, &pos_y_back, 0);
	return_cursor_to_position(pos_back, 'l');
	return (0);
}
