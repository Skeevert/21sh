/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:55:51 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 14:59:14 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

static int		argument_needed_21sh(char *option, char *name)
{
	char		*arg;
	
	arg = ft_strjoin(name, ": ");
	arg = ft_strrejoin(arg, option);
	errno(ERR_OPTIONS, ERR_BTIN_ARG, arg);
	free(arg);
	exit(ERR_OPTIONS);
}

static int		invalid_option_21sh(char *option, char *name)
{
	char		*arg;
	
	arg = ft_strjoin(name, ": ");
	arg = ft_strrejoin(arg, option);
	errno(ERR_OPTIONS, ERR_OPT_BTIN_INVALID, arg);
	free(arg);
	exit(ERR_OPTIONS);
}

int				check_c_option(int argc, char **argv)
{
	int			i;
	int			j;
	int			tmp;

	i = 0;
	tmp = 0;
	if (argc == 1 || (argc > 1 && argv[1][0] != '-'))
		return (0);
	while (argv[++i] && argv[i][0] == '-')
	{
		j = 0;
		if (!argv[i][1])
			return (invalid_option_21sh(argv[i], argv[0]));
		while (argv[i][++j] == 'c' && argv[i][j])
			tmp = i;
		if (argv[i][j] == '-' && !argv[i][j + 1])
			break ;
		if (j > 0 && (!(argv[i][j] == 'c' || argv[i][j] == '\0')))
			return (invalid_option_21sh(&argv[i][j], argv[0]));	
	}
	if (tmp > 0 && !argv[i])
		return (argument_needed_21sh("-c", argv[0]));
	return ((tmp > 0) ? noninteractive_shell(&argv[i]) : 0);
}

int				noninteractive_shell(char **argv)
{
	char		*cmd;
	int			i;
	int			j;

	i = variable_search(&j, "NONINTERACTIVE_MODE");
	g_envi[i][j] = '1';
	cmd = ft_strdup(argv[0]);
	g_prompt.prompt_func = NULL;
	lexparser(cmd);
	i = variable_search(&j, "?");
	exit(ft_atoi(&g_envi[i][j]));
}

int				main(int argc, char **argv, char **environ)
{
	g_var_size = VAR_BUFFER;
	create_env(environ);
	check_c_option(argc, argv);
	g_prompt.prompt_func = main_prompt;
	init_hist_buff();
	init_readline();
	interactive_shell();
	return (0);
}
