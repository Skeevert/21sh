/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edition_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:32:31 by hshawand          #+#    #+#             */
/*   Updated: 2020/07/27 01:10:12 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "edit_line.h"

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
		init_wind_size();
		g_prompt.prompt_func();
		readline_beg();
	}
	return (0);
}

int		readline_beg(void)
{
	char	*out;

	if (g_readline.cmd[0] != 0)
		bzero_readline();
	readline();
	canonical_back();
	signals_define(2);
	out = ft_strtrim(g_readline.cmd);
	if (ft_strlen(out) == 0)
	{
		free(out);
		bzero_readline();
		lexparser(ft_xmalloc(1));
		return (0);
	}
	free(out);
	out = ft_strjoin(g_readline.cmd, "\n");
	bzero_readline();
	lexparser(out);
	return (0);
}

int		readline(void)
{
	char	c;

	while (read(0, &c, 1) > 0 && c != '\n')
	{
		if (ctrl_seq(c) == EXIT)
			return (EXIT);
		if (c == '\033')
			escape_seq();
		else if (ft_isprint(c))
			if (add_char(c, 'u') == EXIT)
				return (EXIT);
	}
	ft_putchar_fd('\n', 1);
	action_alloc_management(NULL, 1);
	return (0);
}
