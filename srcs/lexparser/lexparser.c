/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:08:41 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/31 22:52:49 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "lexparser.h"

int		lexparser(char *line)
{
	if (g_prompt.prompt_func == main_prompt
		&& (line == NULL || line[0] == 0))
	{
		free(line);
		return (0);
	}
	g_cmd = line;
	g_cmd_size = ft_strlen(g_cmd);
	ft_get_techline(g_cmd, &g_techline);
	if (g_prompt.prompt_func != NULL)
		add_history(g_cmd);
	g_hist.count = g_hist.last + 1;
	pars_lex_exec();
	return (0);
}

int		pars_lex_exec(void)
{
	if (g_prompt.prompt_func != heredoc_prompt)
		if (nullify(&g_techline.line, g_cmd_size) == EXIT)
		{
			destruct_parser();
			return (0);
		}
	ft_slice();
	destruct_parser();
	return (0);
}

int		ft_get_techline(char *cmd, t_tech *result)
{
	size_t	i;

	i = 0;
	result->line = (char *)ft_xmalloc(ft_strlen(cmd) + 2);
	while (cmd[i])
	{
		result->line[i] = get_tech_num(cmd[i]);
		i++;
	}
	result->line[i] = END_T;
	result->len = i;
	result->alloc_size = i + 2;
	return (0);
}

int		ltree_init(t_ltree *final)
{
	final->start = 0;
	final->end = 0;
	final->flags = 0;
	final->fd = NULL;
	final->token = NULL;
	final->envir = NULL;
	final->ar_v = NULL;
	final->ar_c = 0;
	final->err = NULL;
	final->err_i = 0;
	final->l_cmd = NULL;
	final->l_tline.line = NULL;
	final->l_tline.len = 0;
	return (0);
}
