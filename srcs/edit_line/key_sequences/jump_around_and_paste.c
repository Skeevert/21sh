#include "sh21.h"
#include "edit_line.h"

/*
** Set ctrl + arrow up
*/

int		jump_up(void)
{
	int				pos_x_goal;
	
	if (g_readline.str_num < 2 || g_readline.pos_y == 0)
		return (incorrect_seq());
	pos_x_goal = g_readline.pos_x;
	while (g_readline.pos_x != 0 && g_readline.pos)
		key_left_proc();
	if (g_readline.pos_x == 0)
	{
		key_left_proc();
		if (g_readline.pos_y == 0 && g_readline.pos_x >
			pos_x_goal + g_prompt.prompt_len)
		{
			while (g_readline.pos_x != pos_x_goal + g_prompt.prompt_len
				&& g_readline.pos)
				key_left_proc();
		}
		else if (g_readline.pos_y > 0 && g_readline.pos_x > pos_x_goal)
		{
			while (g_readline.pos_x != pos_x_goal && g_readline.pos)
				key_left_proc();
		}
	}
	return (0);
}

/*
** Set ctrl + arrow dowp
*/

int		jump_down(void)
{
	int				pos_x_goal;
	int				flag;

	if (g_readline.str_num < 2 || g_readline.pos_y == g_readline.str_num - 1)
		return (incorrect_seq());
	pos_x_goal = (g_readline.pos_y == 0) ? g_readline.pos_x - g_prompt.prompt_len :
		g_readline.pos_x;
	flag = (pos_x_goal == 0) ? 1 : 0;
	if (pos_x_goal == 0)
		key_right_proc();
	while (g_readline.pos_x != 0)
		key_right_proc();
	if (g_readline.pos_x == 0 && (pos_x_goal > 0 || flag == 1))
	{
		key_right_proc();
		if (flag == 1)
			return (key_left_proc());
		while (g_readline.pos_x < pos_x_goal && g_readline.pos_x != 0 &&
			g_readline.pos < g_readline.cmd_len)
			key_right_proc();
		(g_readline.pos_x == 0) ? key_left_proc() : 0;
	}
	return (0);
}

/*
** Change keys to home and end
*/

int		ctrlae_jump_home_end(char c)
{
	int				pos_old;

	if (c == '\001')
	{
		pos_old = 0;
		return_cursor_to_position(pos_old, 'l');
	}
	else
	{
		pos_old = g_readline.cmd_len - 1;
		return_cursor_to_position(pos_old, 'r');
	}
	return (0);
}

int		ctrlp_paste(int mode, char *yank)
{
	static char		*paste_str;

	if (mode == 0)
	{
		(paste_str) ? free(paste_str) : 0;
		if (yank)
			paste_str = yank;
		else
			paste_str = NULL;
	}
	else if (mode == 1)
	{
		if (paste_str == NULL)
			return (incorrect_seq());
		paste_insert(paste_str);
	}
	else if (mode == 2)
		(paste_str) ? free(paste_str) : 0;
	return (0);
}

int		paste_insert(char *paste_str)
{
	char			*save;
	int				i;

	if (g_readline.pos < g_readline.cmd_len && g_readline.cmd[g_readline.pos])
	{
		save = ft_strdup(g_readline.cmd + g_readline.pos);
		ft_bzero(g_readline.cmd + g_readline.pos,
			g_readline.cmd_buff_len - g_readline.pos);
	}
	else
		save = NULL;
	setjmp_cursor(&g_readline.pos, &g_readline.pos_x, &g_readline.pos_y, 1);
	put_termcap("cd");
	i = -1;
	while (paste_str[++i])
		add_char(paste_str[i], 0);
	if (save)
		ft_strcpy(g_readline.cmd + g_readline.pos, save);
	front_insert_till_end(g_readline.pos_y + 1);
	free(save);
	return (0);
}
