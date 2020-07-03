#include "sh21.h"
#include "edit_line.h"

int		posx_for_newline(int nl_pos)
{
	int				len;

	len = 0;
	while (nl_pos)
	{
		len++;
		if (g_readline.cmd[nl_pos] == '\n')
			break ;
		nl_pos--;
	}
	if (nl_pos > 0)
		len -= 1;
	else if (nl_pos == 0 && g_readline.cmd[nl_pos] != '\n')
        len += g_prompt.prompt_len + 1;
	if (len >= g_winsize.ws_col)
		len = len % g_winsize.ws_col;
	return (len);
}

/*
** @side can be left = 'l' or right = 'r'
*/

int		return_cursor_to_position(int pos_old,
			char side)
{
	if (side == 'l')
	{
		while (g_readline.pos != pos_old)
		{
			if (front_move_char_left(g_readline.pos_x))
				return (incorrect_seq());
			g_readline.pos--;
		}
	}
	if (side == 'r')
	{
		while (g_readline.pos != pos_old)
		{
			if (front_move_char_right(g_readline.pos_x))
				return (incorrect_seq());
			g_readline.pos++;
		}
	}
	return (0);
}

int		front_move_char_right(int pos_x)
{
	if (pos_x == g_winsize.ws_col - 1 ||
		g_readline.cmd[g_readline.pos] == '\n')
	{
		put_termcap("cr");
		put_termcap("do");
		g_readline.pos_x = 0;
		g_readline.pos_y++;
	}
	else if (pos_x >= 0 && pos_x < g_winsize.ws_col - 1 &&
			g_readline.cmd[g_readline.pos] != '\n')
	{
		put_termcap("nd");
		g_readline.pos_x++;
	}
	else
		return (1);
	return (0);
}

int		front_move_char_left(int pos_x)
{
	int				prev_x;

	prev_x = 0;
	if (pos_x == 0)
	{
		if (g_readline.pos > 0 &&
			g_readline.cmd[g_readline.pos - 1] == '\n')
			prev_x = posx_for_newline(g_readline.pos - 2);
		else
			prev_x = g_winsize.ws_col - 1;
		put_cursor("ch", 0, prev_x);
		put_termcap("up");
		g_readline.pos_x = prev_x;
		g_readline.pos_y--;
	}
	else if (pos_x > 0)
	{
		put_termcap("le");
		g_readline.pos_x--;
	}
	else
		return (1);
	return (0);
}

/*
** @Flag == 1 means "save position"
** @flag == 0 means "return position"
*/

int		setjmp_cursor(int *pos, int *pos_x,
			int *pos_y, int flag)
{
	static int		pos_save;
	static int		pos_x_save;
	static int		pos_y_save;
	
	if (flag == 1)
	{
		pos_save = *pos;
		pos_x_save = *pos_x;
		pos_y_save = *pos_y;
	}
	if (flag == 0)
	{
		*pos = pos_save;
		*pos_x = pos_x_save;
		*pos_y = pos_y_save;
	}
	return (0);
}