/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_change_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 23:20:07 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/26 15:28:09 by rbednar          ###   ########.fr       */
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
		find_assignment_in_vars(buf, 0, ft_strchri(buf, '='), ft_strlen(buf));
		free(old);
	}
	else
	{
		buf = ft_strjoin("OLDPWD=", pos->envir[k] + j);
		find_assignment_in_vars(buf, 0, ft_strchri(buf, '='), ft_strlen(buf));
		free(buf);
	}
	buf = ft_strjoin("PWD=", *path);
	find_assignment_in_vars(buf, 0, ft_strchri(buf, '='), ft_strlen(buf));
	free(buf);
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
