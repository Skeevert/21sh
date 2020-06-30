#include "sh21.h"
#include "edit_line.h"

void	init_hist_buff(void)
{
	g_hist.len = MAX_HISTORY;
	g_hist.cmd = (char**)ft_xmalloc(sizeof(char*) * (g_hist.len + 1));
	g_hist.last = -1;
	g_hist.count = 0;
}

int		add_history(char *cmd)
{
	int		flag;

	flag = 0;
	if (g_hist.last + 1 >= g_hist.len - 1 &&
		g_prompt.prompt_func == main_prompt && g_hist.len > 0)
		scroll_hist_buffer(1);
	if (g_prompt.prompt_func == main_prompt && g_hist.len > 0)
	{
		g_hist.last++;
		g_hist.cmd[g_hist.last] = ft_strdup(cmd);
	}
	else if (g_prompt.prompt_func != main_prompt &&
		g_prompt.prompt_func != heredoc_prompt && g_hist.len > 0)
	{
		flag = (cmd[0] == EOF) ? EOF : 0;
		add_history_eof_cmd(cmd, flag);
	}
	return (0);
}

int		add_history_eof_cmd(char *cmd, int flag)
{
	if (g_hist.cmd[g_hist.last][0] != 0 && flag == 0)
		g_hist.cmd[g_hist.last] =
			ft_strrejoin(g_hist.cmd[g_hist.last], cmd);
	destruct_parser();
	g_cmd = ft_strdup(g_hist.cmd[g_hist.last]);
	g_cmd = (flag == EOF) ? ft_straddsy(g_cmd, EOF) : g_cmd;
	g_cmd_size = ft_strlen(g_cmd);
	ft_get_techline(g_cmd, &g_techline);
	return (0);
}

int		scroll_hist_buffer(int num)
{
	int		i;

	i = 0;
	while (i < num)
	{
		free(g_hist.cmd[i]);
		g_hist.cmd[i] = NULL;
		i++;
	}
	i = 0;
	while (i < g_hist.len - num)
	{
		g_hist.cmd[i] = g_hist.cmd[i + num];
		i++;
	}
	g_hist.last -= num;
	g_hist.count = g_hist.last + 1;
	return (0);
}
