/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_change_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 23:20:07 by rbednar           #+#    #+#             */
/*   Updated: 2020/06/10 18:51:56 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "builtin.h"

int		ft_del_slash(char **str)
{
	char	*tmp;
	int		i;

	tmp = ft_xmalloc(sizeof(char));
	i = 0;
	while ((*str)[i])
	{
		while ((*str)[i] == '/' && (*str)[i + 1] == '/')
			i++;
		tmp = ft_strrejoin(tmp, &((*str)[i]));
		i++;
	}
	free(*str);
	*str = tmp;
	return (0);
}

int		ft_to_dir(char *path)
{
	if (chdir(path) == -1)
	{
		ft_error(path, CD_N_PERMISSION);
		return (1);
	}
	return (0);
}

void	ft_change_pwd(char **path, t_ltree *pos)
{
	size_t	j;
	size_t	k;
	char	*old;
	char	*buf;

	k = find_in_variables(pos->envir, &j, "PWD");
	if (k == (size_t)-1)
	{
		old = getcwd(NULL, 0);
		buf = ft_strjoin("OLDPWD=", old);
		add_new_to_exec_env(&(pos->envir), &buf);
		free(old);
	}
	else
	{
		buf = ft_strjoin("OLDPWD=", pos->envir[k] + j);
		add_new_to_exec_env(&(pos->envir), &buf);
	}
	buf = ft_strjoin("PWD=", *path);
	add_new_to_exec_env(&(pos->envir), &buf);
}

int		ft_change_path(char **path, t_ltree *pos)
{
	if (ft_to_dir(*path))
	{
		free(*path);
		return (1);
	}
	ft_change_pwd(path, pos);
	free(*path);
	return (0);
}
