#include "sh21.h"
#include "edit_line.h"

int					signals_define(int from)
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
		signal(SIGINT, signal_ctrl_c_parser);
		signal(SIGTSTP, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGCONT, SIG_IGN);
	}
	return (0);
}

void				signal_ctrl_c_readline(int sig)
{
	ft_putchar_fd('\n', 1);
	g_prompt.prompt_func = main_prompt;
	g_prompt.prompt_func();
	bzero_readline();
	signal(SIGINT, signal_ctrl_c_readline);
}

void				signal_ctrl_c_parser(int sig)
{
	signal(SIGINT, signal_ctrl_c_parser);
}

void				signal_screen(int sig)
{
	setjmp_cursor(&g_readline.pos, &g_readline.pos_x, &g_readline.pos_y, 1);
	return_cursor_to_position(0, 'l');
	put_cursor("ch", 0, 0);
	put_termcap("cd");
	ioctl(1, TIOCGWINSZ, &g_winsize);
	g_prompt.prompt_func();
	if (g_prompt.prompt_len >= g_winsize.ws_col)
		g_readline.pos_x = g_prompt.prompt_len % g_winsize.ws_col;
	front_insert_till_end(g_readline.pos_y + 1);
}
