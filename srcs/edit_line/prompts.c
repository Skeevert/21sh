/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:34:11 by hshawand          #+#    #+#             */
/*   Updated: 2020/08/01 17:58:52 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "edit_line.h"

int				main_prompt(void)
{
	const char	*prompt = "21sh";
	int			len;

	ft_putstr_fd("\033[1;33m", STDOUT_FILENO);
	ft_putstr_fd(prompt, STDOUT_FILENO);
	ft_putstr_fd("\033[0m", STDOUT_FILENO);
	ft_putstr_fd("> ", STDOUT_FILENO);
	len = ft_strlen(prompt) + 2;
	g_prompt.prompt_len = prompt_len_by_winsize(len);
	return (0);
}

int				heredoc_prompt(void)
{
	int			len;

	ft_putstr_fd("heredoc> ", STDOUT_FILENO);
	len = 9;
	g_prompt.prompt_len = prompt_len_by_winsize(len);
	return (0);
}

int				other_prompt(void)
{
	int			len;

	ft_putstr_fd("> ", STDOUT_FILENO);
	len = 2;
	g_prompt.prompt_len = prompt_len_by_winsize(len);
	return (0);
}

int				route_exit(void)
{
	t_ltree	*pos;

	if (g_prompt.prompt_func == main_prompt)
	{
		pos = (t_ltree*)ft_xmalloc(sizeof(t_ltree));
		ltree_init(pos);
		pos->ar_v = (char**)ft_xmalloc(3 * sizeof(char*));
		pos->ar_v[0] = ft_strdup("exit");
		pos->ar_v[1] = ft_strdup("0");
		action_alloc_management(NULL, 1);
		canonical_back();
		free(g_readline.cmd);
		btin_exit(pos);
	}
	if (g_prompt.prompt_func != main_prompt)
	{
		if (g_readline.cmd_len >= g_readline.cmd_buff_len - 1)
			realloc_readline_cmd();
		g_readline.cmd = ft_straddsy(g_readline.cmd, EOF);
		g_readline.cmd[0] == EOF ? ft_putchar_fd('\n', STDOUT_FILENO) : 0;
		return (EXIT);
	}
	return (0);
}

int				prompt_len_by_winsize(int len)
{
	int			new;

	if (len >= g_winsize.ws_col)
		new = len % g_winsize.ws_col;
	else
		new = len;
	if (new == 0)
	{
		put_termcap("sf");
		g_readline.flag |= NEW_LINE_SY;
		g_readline.flag |= PROMPTLEN_ZERO;
	}
	return (new);
}
