/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 14:54:00 by hshawand          #+#    #+#             */
/*   Updated: 2020/08/07 21:36:14 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "lexparser.h"

char	**path_parse(void)
{
	char	**ret;
	int		li;
	int		co;

	ret = NULL;
	li = variable_search(&co, "PATH");
	if (li < 0 || ((ret = ft_strsplit(&g_envi[li][co], ':')) == NULL) ||
			ret[0] == NULL || ret[0][0] == '\0')
	{
		ft_arrdel(ret);
		return (NULL);
	}
	return (ret);
}

char	*form_path(char *ret, char *env_path, t_ltree *pos)
{
	ft_bzero(ret, ft_strlen(env_path) + ft_strlen(*pos->ar_v) + 2);
	ft_strcpy(ret, env_path);
	ft_strcat(ret, "/");
	ft_strcat(ret, *pos->ar_v);
	if (access(ret, X_OK) == -1)
	{
		pos->flags = ERR_CMDEXEC;
		errno(ERR_CMDEXEC, ERR_CMDEXEC, *pos->ar_v);
		free(ret);
		ret = NULL;
	}
	return (ret);
}

char	*locate_file(char *env_path, t_ltree *pos)
{
	t_dirent	*dir;
	char		*ret;
	DIR			*path;

	ret = NULL;
	path = opendir(env_path);
	if (path == NULL)
		return (NULL);
	while ((dir = readdir(path)))
	{
		if (!ft_strcmp(dir->d_name, *pos->ar_v))
		{
			ret = (char *)ft_xmalloc(ft_strlen(env_path) +
				ft_strlen(*pos->ar_v) + 2);
			break ;
		}
	}
	closedir(path);
	return (ret);
}

/*
** This is "just executable name case". We should check all
** directories in $PATH, find first match and check its accessibility
*/

char	*path_search(t_ltree *pos)
{
	char			**path_array;
	char			**to_clean;
	char			*ret;

	if (!(path_array = path_parse()))
		return (0);
	to_clean = path_array;
	while (*path_array)
	{
		ret = locate_file(*path_array, pos);
		if (ret)
		{
			ret = form_path(ret, *path_array, pos);
			break ;
		}
		path_array++;
	}
	ft_arrdel(to_clean);
	return (ret);
}

/*
** Here we should find check and return execpath
*/

char	*path_init(t_ltree *pos, char **ret)
{
	t_stat	stat_buf;

	*ret = NULL;
	if (pos->ar_c == 0)
		return (*ret);
	if (!ft_strchr(*pos->ar_v, '/'))
		*ret = path_search(pos);
	else
	{
		if (access(*pos->ar_v, X_OK) == -1 || stat(*pos->ar_v, &stat_buf) != 0
			|| (stat_buf.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) == 0 ||
			S_ISREG(stat_buf.st_mode) == 0)
		{
			if (stat(*pos->ar_v, &stat_buf) == 0 && S_ISDIR(stat_buf.st_mode))
				pos->err_i = ERR_ISDIR;
			else if (S_ISREG(stat_buf.st_mode))
				pos->err_i = ERR_CMDEXEC;
			else
				pos->err_i = ERR_NOFILEDIR;
			return (NULL);
		}
		*ret = ft_strdup(*pos->ar_v);
	}
	return (*ret);
}
