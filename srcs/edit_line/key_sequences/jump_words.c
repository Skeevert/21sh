/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:31:18 by hshawand          #+#    #+#             */
/*   Updated: 2020/07/25 17:31:19 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "edit_line.h"

/*
** Jump to word start
*/

int		escb_jump_word_left(void)
{
	int		i;
	int		pos_old;

	if (g_readline.pos == 1 || g_readline.pos == 2)
		return (word_left_onetwo_chars());
	else if (g_readline.pos <= 0)
		return (incorrect_seq());
	i = g_readline.pos - 1;
	while (i > 0 && g_readline.cmd[i - 1] && g_readline.cmd[i])
	{
		if (ft_isalnum(g_readline.cmd[i]) && !ft_isalnum(g_readline.cmd[i - 1]))
			break ;
		i--;
	}
	pos_old = i;
	if (return_cursor_to_position(pos_old, 'l'))
		return (-1);
	return (0);
}

/*
** help to work whit position in start
*/

int		word_left_onetwo_chars(void)
{
	int		pos_old;

	pos_old = g_readline.pos;
	if (front_move_char_left(g_readline.pos_x))
		return (incorrect_seq());
	g_readline.pos--;
	if (pos_old == 2)
	{
		if (front_move_char_left(g_readline.pos_x))
			return (incorrect_seq());
		g_readline.pos--;
	}
	return (0);
}

/*
** Jump to word end
*/

int		escf_jump_word_right(void)
{
	int		i;
	int		pos_old;

	if (g_readline.pos == g_readline.cmd_len || g_readline.pos < 0)
		return (incorrect_seq());
	else if (g_readline.pos == g_readline.cmd_len - 1)
	{
		if (front_move_char_right(g_readline.pos_x))
			return (incorrect_seq());
		return (0);
	}
	i = g_readline.pos + 1;
	while (g_readline.cmd[i] && g_readline.cmd[i - 1])
	{
		if (!ft_isalnum(g_readline.cmd[i]) && ft_isalnum(g_readline.cmd[i - 1]))
			break ;
		i++;
	}
	pos_old = i;
	if (return_cursor_to_position(pos_old, 'r'))
		return (-1);
	return (0);
}

char	*save_word(int *i, char *cmd, int pos)
{
	char	*word;

	word = NULL;
	*i = 0;
	while (ft_isalnum(cmd[pos + *i]))
		(*i)++;
	word = ft_strndup(cmd + pos, *i);
	return (word);
}

char	*save_end(int pos_back)
{
	char	*end;
	size_t	pos_now;

	end = NULL;
	pos_now = g_readline.pos;
	return_cursor_to_position(pos_back, 'r');
	if (escf_jump_word_right())
		return (end);
	end = ft_strdup(g_readline.cmd + g_readline.pos);
	return_cursor_to_position(pos_now, 'l');
	return (end);
}
