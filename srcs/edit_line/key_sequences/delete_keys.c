#include "sh21.h"
#include "edit_line.h"

int		backspace_process(void)
{
	char	*cmd_end;
	int		len_cmd_end;

	if (g_readline.pos > 0)
	{
		undo(0);
		cmd_end = g_readline.cmd + g_readline.pos;
		len_cmd_end = ft_strlen(cmd_end);
		if (g_readline.cmd[g_readline.pos - 1] == '\n')
			return (backspace_newline(cmd_end, len_cmd_end));
		ft_strcpy(g_readline.cmd + g_readline.pos - 1, cmd_end);
		ft_bzero(g_readline.cmd + g_readline.pos - 1 + len_cmd_end,
			g_readline.cmd_buff_len - g_readline.cmd_len);
		g_readline.cmd_len--;
		key_left_proc();
		setjmp_cursor(&g_readline.pos, &g_readline.pos_x,
			&g_readline.pos_y, 1);
		put_termcap("cd");
		front_insert_till_end(g_readline.pos_y + 1);
	}
	else
		return (incorrect_seq());
	return (0);
}

int		backspace_newline(char *cmd_end, int len_cmd_end)
{
	int		pos_back;

	pos_back = g_readline.pos;
	key_left_proc();
	setjmp_cursor(&g_readline.pos, &g_readline.pos_x,
		&g_readline.pos_y, 1);
	ft_strcpy(g_readline.cmd + pos_back - 1, cmd_end);
	ft_bzero(g_readline.cmd + pos_back - 1 + len_cmd_end,
		g_readline.cmd_buff_len - g_readline.cmd_len);
	g_readline.cmd_len--;
	put_termcap("cd");
	front_insert_till_end(g_readline.pos_y + 1);
	return (0);
}

int		delete_process(void)
{
	if (g_readline.pos == 0 && g_readline.cmd_len == 0)
	{
		if (route_exit() == EXIT)
			return (EXIT);
	}
	return (0);
}

int		clean_cmd(void)
{
	while (g_readline.pos)
		key_left_proc();
	put_termcap("cd");
	ft_bzero(g_readline.cmd, g_readline.cmd_buff_len);
	g_readline.cmd_len = 0;
	g_readline.flag = 0;
	return (0);
}
