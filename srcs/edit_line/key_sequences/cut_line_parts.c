/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_line_parts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:25:50 by hshawand          #+#    #+#             */
/*   Updated: 2020/07/25 17:48:13 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "edit_line.h"

int		ctrlk_cut_till_end(void)
{
	char	*save_paste;

	if (g_readline.pos < 0 || g_readline.pos == g_readline.cmd_len)
		return (incorrect_seq());
	undo(0);
	save_paste = ft_strdup(g_readline.cmd + g_readline.pos);
	g_readline.cmd_len -= ft_strlen(g_readline.cmd + g_readline.pos);
	ctrlp_paste(0, save_paste);
	put_termcap("cd");
	ft_bzero(g_readline.cmd + g_readline.pos,
		ft_strlen(g_readline.cmd + g_readline.pos));
	return (0);
}

int		ctrlu_cut_till_beg(void)
{
	int		pos_old;
	char	*cmd_end;
	int		len_end;
	char	*save_paste;

	if (g_readline.pos <= 0)
		return (incorrect_seq());
	undo(0);
	pos_old = g_readline.pos;
	while (g_readline.pos)
		key_left_proc();
	setjmp_cursor(&g_readline.pos,
		&g_readline.pos_x, &g_readline.pos_y, 1);
	save_paste = (pos_old == g_readline.cmd_len) ?
		ft_strdup(g_readline.cmd + g_readline.pos) :
		ft_strndup(g_readline.cmd + g_readline.pos, pos_old - g_readline.pos);
	ctrlp_paste(0, save_paste);
	cmd_end = g_readline.cmd + pos_old;
	len_end = ft_strlen(cmd_end);
	ft_strcpy(g_readline.cmd, cmd_end);
	ft_bzero(g_readline.cmd + len_end, g_readline.cmd_buff_len - len_end);
	g_readline.cmd_len = 0 + len_end;
	put_termcap("cd");
	front_insert_till_end(g_readline.pos_y + 1);
	return (0);
}

int		ctrlw_cut_till_word_beg(void)
{
	int		pos_old;
	char	*cmd_end;
	int		len_cmd_end;
	char	*save_paste;

	undo(0);
	pos_old = g_readline.pos;
	if (escb_jump_word_left())
		return (0);
	save_paste = (pos_old >= g_readline.cmd_len) ?
		ft_strdup(g_readline.cmd + g_readline.pos) :
		ft_strndup(g_readline.cmd + g_readline.pos, pos_old - g_readline.pos);
	ctrlp_paste(0, save_paste);
	cmd_end = g_readline.cmd + pos_old;
	len_cmd_end = ft_strlen(cmd_end);
	g_readline.cmd_len = g_readline.pos + len_cmd_end;
	ft_strcpy(g_readline.cmd + g_readline.pos, cmd_end);
	ft_bzero(g_readline.cmd + g_readline.pos + len_cmd_end,
		g_readline.cmd_buff_len - g_readline.cmd_len);
	setjmp_cursor(&g_readline.pos,
		&g_readline.pos_x, &g_readline.pos_y, 1);
	put_termcap("cd");
	front_insert_till_end(g_readline.pos_y + 1);
	return (0);
}

int		escd_cut_till_word_end(void)
{
	int		pos_old;
	char	*cmd_end;
	int		len_cmd_end;
	char	*save_paste;

	pos_old = g_readline.pos;
	if (escf_jump_word_right())
		return (0);
	undo(0);
	save_paste = (g_readline.pos == g_readline.cmd_len) ?
		ft_strdup(g_readline.cmd + pos_old) :
		ft_strndup(g_readline.cmd + pos_old, g_readline.pos - pos_old);
	ctrlp_paste(0, save_paste);
	cmd_end = g_readline.cmd + g_readline.pos;
	len_cmd_end = ft_strlen(cmd_end);
	g_readline.cmd_len = pos_old + len_cmd_end;
	ft_strcpy(g_readline.cmd + pos_old, cmd_end);
	ft_bzero(g_readline.cmd + pos_old + len_cmd_end,
		g_readline.cmd_buff_len - g_readline.cmd_len);
	return_cursor_to_position(pos_old, 'l');
	setjmp_cursor(&g_readline.pos,
		&g_readline.pos_x, &g_readline.pos_y, 1);
	put_termcap("cd");
	front_insert_till_end(g_readline.pos_y + 1);
	return (0);
}
