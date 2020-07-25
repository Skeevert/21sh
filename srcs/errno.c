/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:08:15 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 16:08:16 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

int		errno(int status, int errtype, char *name)
{
	ft_putstr_fd("21sh: ", 2);
	if (status == ERR_NONINTERACTIVE)
	{
		ft_putstr_fd(name, 2);
		ft_putendl_fd(": can't be launched in non-interactive mode", 2);
	}
	else if (status == ERR_TERMINAL)
		ft_putendl_fd("terminal does not exist or can't be changed", 2);
	else if (status == ERR_TMPFILE)
		ft_putendl_fd("can't open a temporal file", 2);
	else if (errtype == ERR_CMDEXEC)
	{
		ft_putstr_fd(name, 2);
		ft_putendl_fd(": Permission denied", 2);
	}
	else if (errtype == ERR_ISDIR)
	{
		ft_putstr_fd(name, 2);
		ft_putendl_fd(": Is a directory", 2);
	}
	else if (errtype == ERR_PIPE)
		ft_putendl_fd("Pipe failed", 2);
	errtypes_first(errtype, name);
	errtypes_second(errtype, name);
	return (var_exit_status(status & 0x7F));
}

int		errtypes_first(int errtype, char *name)
{
	if (errtype == ERR_VAR_SET || errtype == ERR_VAR_CD)
	{
		ft_putendl_fd(name, 2);
		return (0);
	}
	ft_putstr_fd(name, 2);
	if (errtype == ERR_VAR_RDONLY)
		ft_putendl_fd(": readonly variable", 2);
	else if (errtype == ERR_VAR_UNSET)
		ft_putendl_fd(": parameter null or not set", 2);
	else if (errtype == ERR_OPT_BTIN_INVALID)
		ft_putendl_fd(": invalid option", 2);
	else if (errtype == ERR_BTIN_ARG)
		ft_putendl_fd(": option requires an argument", 2);
	else if (errtype == ERR_NOCMD)
		ft_putendl_fd(": command not found", 2);
	else if (errtype == ERR_NOFILEDIR)
		ft_putendl_fd(": No such file or directory", 2);
	else if (errtype == ERR_FD)
		ft_putendl_fd(": Bad file descriptor", 2);
	else if (errtype == ERR_NOACCESS)
		ft_putendl_fd(": Permission denied", 2);
	return (0);
}

int		errtypes_second(int errtype, char *name)
{
	if (errtype == ERR_SQUOTE)
	{
		ft_putstr_fd("unexpected EOF while looking for matching `", 2);
		ft_putstr_fd(name, 2);
		ft_putendl_fd("'", 2);
		ft_putstr_fd("21sh: ", 2);
		ft_putstr_fd("syntax error: ", 2);
		ft_putendl_fd("unexpected end of file", 2);
	}
	else if (errtype == ERR_SYNTAX)
	{
		ft_putstr_fd("syntax error near unexpected token `", 2);
		ft_putstr_fd(name, 2);
		ft_putendl_fd("'", 2);
	}
	return (0);
}

int		exit_status_variable(void)
{
	int		li;
	int		sy;
	
	li = variable_search(&sy, "?");
	return (ft_atoi(&g_envi[li][sy]));
}
