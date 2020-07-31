/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_change_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 23:20:07 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/31 22:31:18 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "builtins.h"

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

int		ft_add_varspwd(char **buf, char *find)
{
	int		eq;
	int		len;

	len = ft_strlen(*buf);
	eq = ft_strchri(*buf, '=');
	find_assignment_in_vars(*buf, 0, eq, len);
	eq = variable_search(&len, find);
	g_envi[eq][0] |= ENV_VIS;
	free(*buf);
	return (0);
}

void	ft_change_pwd(char **path, t_ltree *pos)
{
	int		j;
	int		k;
	char	*old;
	char	*buf;

	k = find_in_variables(pos->envir, &j, "PWD");
	if (k == -1)
	{
		old = getcwd(NULL, 0);
		buf = ft_strjoin("OLDPWD=", old);
		ft_add_varspwd(&buf, "OLDPWD");
		free(old);
	}
	else
	{
		buf = ft_strjoin("OLDPWD=", pos->envir[k] + j);
		ft_add_varspwd(&buf, "OLDPWD");
	}
	buf = ft_strjoin("PWD=", *path);
	ft_add_varspwd(&buf, "PWD");
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
