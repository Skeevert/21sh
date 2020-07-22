/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_management.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:07:58 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/22 18:14:36 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_MANAGEMENT_H
# define ERRORS_MANAGEMENT_H

enum				e_exit
{
	SUCCESS,
	ERR_VARIABLE,
	ERR_OPTIONS,
	ERR_MALLOC = 100,
	ERR_TERMINAL,
	ERR_NONINTERACTIVE,
	ERR_TMPFILE,
	ERR_CMDEXEC = 126,
	ERR_CMDNOTFOUND,
	ERR_SYNTAX = 258,
	ERR_ISDIR,
	ERR_PIPE
};

enum				e_errtype
{
	ERR_VAR_RDONLY = 1,
	ERR_VAR_UNSET,
	ERR_VAR_SET,
	ERR_VAR_CD,
	ERR_OPT_BTIN_INVALID = 10,
	ERR_BTIN_ARG,
	ERR_NOCMD = 20,
	ERR_NOFILEDIR,
	ERR_SQUOTE = 30,
	ERR_REDIR,
	ERR_FD,
	ERR_NOACCESS,
};

#endif
