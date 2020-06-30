#include "sh21.h"
#include "edit_line.h"

/*
** First we check if 42sh program was launched in
** the background. We compare the process group that
** is considered as a controlling terminal owner with
** the pid of the group we are in. If controlling terminal
** does not belong to our group - we stop our group with
** SIGTTIN signal. After we get back to the foreground,
** we continue the work as thought we were launched in the
** foreground from the very beginning.
*/

int		interactive_shell(void)
{
	char	*term;
	char	temp[200];
	int		tmp;

	while (1)
	{
		signals_define(1);
		term = getenv("TERM");
		tmp = tgetent(temp, term);
		if (term == NULL || tmp != 1 || !isatty(STDIN_FILENO) ||
			noncanonical() == -1)
		{
			errno(ERR_TERMINAL, 0, NULL);
			free(g_readline.cmd);
			destruct_globals();
			exit(ERR_TERMINAL);
		}
		g_prompt.prompt_func();
		if (g_readline.cmd[0] != 0)
			bzero_readline();
		readline_beg();
	}
	return (0);
}

void	init_readline(void)
{
	if (ioctl(1, TIOCGWINSZ, &g_winsize))
	{
		errno(ERR_TERMINAL, 0, NULL);
		destruct_globals();
		exit(ERR_TERMINAL);
	}
	g_readline.cmd = (char *)ft_xmalloc(CMD_SIZE + 1);
	g_readline.cmd_len = 0;
	g_readline.pos = 0;
	g_readline.pos_x = g_prompt.prompt_len;
	if (g_prompt.prompt_len >= g_winsize.ws_col)
		g_readline.pos_x = g_prompt.prompt_len % g_winsize.ws_col;
	g_readline.pos_y = 0;
	g_readline.str_num = 1;
	g_readline.cmd_buff_len = CMD_SIZE + 1;
	g_readline.flag = 0;
}

void	bzero_readline(void)
{
	ft_bzero(g_readline.cmd, g_readline.cmd_buff_len);
	g_readline.cmd_len = 0;
	g_readline.pos = 0;
	g_readline.pos_x = g_prompt.prompt_len;
	if (g_prompt.prompt_len >= g_winsize.ws_col)
		g_readline.pos_x = g_prompt.prompt_len % g_winsize.ws_col;
	g_readline.pos_y = 0;
	g_readline.str_num = 1;
	g_readline.flag = 0;
}

int		readline_beg(void)
{
	char	*out;
	char	*tmp;

	readline();
	canonical_back();
	signals_define(2);
	tmp = ft_strtrim(g_readline.cmd);
	if (ft_strlen(tmp) == 0)
	{
		free(tmp);
		bzero_readline();
		lexparser(ft_xmalloc(1));
		return (0);
	}
	if (g_readline.cmd_len == 0)
		out = ft_strdup(g_readline.cmd);
	else
		out = ft_strjoin(g_readline.cmd, "\n");
	free(tmp);
	bzero_readline();
	lexparser(out);
	return (0);
}

int		readline(void)
{
	char	c;

	while (read(1, &c, 1) > 0 && c != '\n')
	{
		if (ctrl_seq(c) == EXIT)
			return (EXIT);
		if (c == '\033')
			escape_seq();
		else if (ft_isprint(c))
			add_char(c, 'u');
	}
	ft_putchar_fd('\n', 1);
	action_alloc_management(NULL, 1);
	return (0);
}