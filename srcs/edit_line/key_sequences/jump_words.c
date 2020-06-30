#include "sh21.h"
#include "edit_line.h"

int		escb_jump_word_left(void)
{
	int		i;
	int		pos_old;

	if (g_readline.pos == 1 || g_readline.pos == 2)
	{
		pos_old = g_readline.pos;
		front_move_char_left(g_readline.pos_x);
		g_readline.pos--;
		(pos_old == 2) ? front_move_char_left(g_readline.pos_x) : 0;
		(pos_old == 2) ? g_readline.pos-- : 0;
		return (0);
	}
	else if (g_readline.pos == 0)
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

int		escf_jump_word_right(void)
{
	int		i;
	int		pos_old;

	if (g_readline.pos == g_readline.cmd_len)
		return (incorrect_seq());
	else if (g_readline.pos == g_readline.cmd_len - 1)
	{
		front_move_char_right(g_readline.pos_x);
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
