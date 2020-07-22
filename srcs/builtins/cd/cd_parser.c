/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 23:19:10 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/22 22:20:50 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "builtins.h"

int		ft_cd_env(char *path, t_ltree *pos)
{
	char	*name;
	int		i;
	int		j;

	name = path ? ft_strdup("OLDPWD") : ft_strdup("HOME");
	if (name)
		i = variable_search(&j, name);
	if (path && i == -1)
	{
		free(name);
		return (ft_error(NULL, CD_OLDPWD_NS));
	}
	free(name);
	if (path != NULL)
		ft_putendl_fd((pos->envir)[i] + j, STDOUT_FILENO);
	if (i == -1)
		name = ft_parsing_str("~");
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

/*
** Is needed for finding a variable in an array
** Returns line on which the value is found or -1 if there is no
** value in the array
*/

int		find_in_variables(char **arr, int *j, char *name)
{
	size_t	i;
	size_t	tmp;
	size_t	len_name;

	i = 0;
	if (!arr)
		return (-1);
	len_name = ft_strlen(name);
	while (arr[i])
	{
		tmp = ft_strchri(arr[i], '=');
		if (ft_strncmp(arr[i], name, len_name) == 0 && tmp == len_name)
		{
			*j = tmp + 1;
			return (i);
		}
		i++;
	}
	return (-1);
}
