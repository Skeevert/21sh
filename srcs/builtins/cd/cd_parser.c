/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 23:19:10 by rbednar           #+#    #+#             */
/*   Updated: 2020/06/03 18:14:39 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"

int		ft_cd_env(char *path, t_ltree *pos)
{
	char	*name;
	size_t	i;
	size_t	j;

	name = path ? ft_strdup("OLDPWD") : ft_strdup("HOME");
	if (name)
		i = find_in_variables(pos->envir, &j, name);
	if (path && i == (size_t)-1)
	{
		free(name);
		return (ft_error(NULL, CD_OLDPWD_NS));
	}
	free(name);
	if (path != NULL)
		ft_putendl_fd((pos->envir)[i] + j, STDOUT_FILENO);
	if (i == (size_t)-1)
		name = ft_parsing_str(pos->envir, "~");
	else
		name = ft_strdup((pos->envir)[i] + j);
	return (ft_change_path(&name, pos));
}

int		ft_cd_pars(char *path, t_ltree *pos)
{
	t_stat	buf;
	char	*new_path;

	if (path == NULL || ft_strcmp(path, "-") == 0)
		return (ft_cd_env(path, pos));
	if (stat(path, &buf) < 0)
		return (ft_error(path, CD_N_FILE_DIR));
	else if (!S_ISDIR(buf.st_mode))
		return (ft_error(path, CD_NOT_DIR));
	else
	{
		new_path = ft_new_path(path, pos->envir);
		return (ft_change_path(&new_path, pos));
	}
	return (0);
}

int		ft_valid_cd(t_ltree *pos, int i)
{
	if (pos->ar_v[i] && pos->ar_v[i + 1])
	{
		ft_error(NULL, CD_MANY_ARGS);
		return (1);
	}
	return (0);
}
