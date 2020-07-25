/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:07:24 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/25 17:54:35 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_LIST_H
# define BUILTINS_LIST_H

# define BUILTINS_NUM 7

static char		*g_builtins[] = {"setenv", "unsetenv", "env", \
	"cd", "echo", "exit", NULL};

static int		(*g_builtins_func[BUILTINS_NUM])() = {btin_setenv, \
	btin_unsetenv, btin_env, btin_cd, btin_echo, btin_exit, NULL};

#endif
