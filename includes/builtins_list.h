/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:07:24 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/22 22:35:31 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_LIST_H
# define BUILTINS_LIST_H

# define BUILTINS_NUM 9

static char		*g_builtins[] = {"setenv", "unsetenv", "env", "set", "unset"\
	"cd", "exit", "echo", NULL};

static int 		(*g_builtins_func[BUILTINS_NUM])() = {btin_setenv, btin_unsetenv, btin_env, \
	btin_set, btin_unset, btin_cd, btin_exit, btin_echo, NULL};

#endif
