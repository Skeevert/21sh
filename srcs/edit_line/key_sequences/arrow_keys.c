#include "sh21.h"
#include "edit_line.h"

int		key_right_proc(void)
{
	if (g_readline.pos >= g_readline.cmd_len)
		return (incorrect_seq());
	front_move_char_right(g_readline.pos_x);
	g_readline.pos++;
	return (0);
}

int		key_left_proc(void)
{
	if (g_readline.pos == 0)
		return (incorrect_seq());
	front_move_char_left(g_readline.pos_x);
	g_readline.pos--;
	return (0);
}

int		key_up_proc(void)
{
	int		i;
	int		len;

	if (g_hist.count <= 0)
	{
		g_hist.count = 0;
		return (0);
	}
	if (g_readline.cmd[0] && g_hist.count <= g_hist.last)
	{
		free(g_hist.cmd[g_hist.count]);
		g_hist.cmd[g_hist.count] = ft_strdup(g_readline.cmd);
	}
	(g_readline.cmd[0]) ? clean_cmd() : 0;
	g_hist.count--;
	i = -1;
	len = ft_strlen(g_hist.cmd[g_hist.count]);
	if (len > 0 && g_hist.cmd[g_hist.count][len - 1] == '\n')
		len--;
	while (++i < len)
		add_char(g_hist.cmd[g_hist.count][i], 'u');
	return (0);
}

int		key_down_proc(void)
{
	int		i;
	int		len;

	if (g_readline.cmd[0] && g_hist.count <= g_hist.last)
	{
		free(g_hist.cmd[g_hist.count]);
		g_hist.cmd[g_hist.count] = ft_strdup(g_readline.cmd);
	}
	(g_readline.cmd[0]) ? clean_cmd() : 0;
	if (g_hist.count >= g_hist.last)
	{
		g_hist.count = g_hist.last + 1;
		return (0);
	}
	g_hist.count++;
	i = -1;
	len = ft_strlen(g_hist.cmd[g_hist.count]);
	if (len > 0 && g_hist.cmd[g_hist.count][len - 1] == '\n')
		len--;
	while (++i < len)
		add_char(g_hist.cmd[g_hist.count][i], 'u');
	return (0);
}
