/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladlenaskubis <vladlenaskubis@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:07:24 by rbednar           #+#    #+#             */
/*   Updated: 2020/03/28 01:41:57 by vladlenasku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_LIST_H
# define BUILTINS_LIST_H

# define BUILTINS_NUM 7

static char		*g_builtins[] = {"setenv", "unsetenv", "env, \
	cd", "exit", "echo", NULL};

static int 		(*g_builtins_func[BUILTINS_NUM])() = {NULL, NULL, NULL, \
	btin_cd, btin_exit, btin_echo, NULL};

#endif
