#include "sh21.h"

int		destruct_globals(void)
{
	int		i;
	int		j;
	
	i = variable_search(&j, "NONINTERACTIVE_MODE");
	if (g_envi[i][j] == '0')
	{
		ft_arrdel(g_hist.cmd);
		ctrlp_paste(2, NULL);
	}
	ft_arrdel(g_envi);
	ft_gnl(GNL_CLEAN, NULL);
	return (0);
}

/*
** The main globals in lexparser
** @g_start_list is a list that comes to execution of commands
*/

int		destruct_parser(void)
{
	if (g_cmd)
		free(g_cmd);
	if (g_techline.line)
		free(g_techline.line);
	if (g_prompt.prompt_func != heredoc_prompt)
		ft_lst_ltree_clear(&g_start_list);
	return (0);
}
