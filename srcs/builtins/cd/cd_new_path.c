/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_new_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 23:19:24 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/22 20:38:01 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "builtins.h"

void	ft_del_prev(char **arr, int i)
{
	while (i > 0)
	{
		if (ft_strcmp(arr[i], ".") && ft_strcmp(arr[i], ".."))
		{
			free(arr[i]);
			arr[i] = ft_strdup(".");
			break ;
		}
		i--;
	}
}

void	ft_del_dots(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (ft_strcmp(arr[i], "..") == 0)
			ft_del_prev(arr, i);
		i++;
	}
}

char	*ft_new_from_arr(char **arr)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char*)ft_xmalloc(sizeof(char));
	ft_del_dots(arr);
	while (arr[i])
	{
		if (ft_strcmp(arr[i], ".") && ft_strcmp(arr[i], ".."))
		{
			tmp = ft_strrejoin(tmp, "/");
			tmp = ft_strrejoin(tmp, arr[i]);
		}
		i++;
	}
	return (tmp);
}

char	*ft_join_path(char *path, char **env)
{
	int		i;
	int		j;
	char	*tmp;

	if (path[0] != '/')
	{
		i = variable_search(&j, "PWD");
		tmp = ft_strjoin(env[i] + j, "/");
		tmp = ft_strrejoin(tmp, path);
	}
	else
		tmp = ft_strdup(path);
	return (tmp);
}

char	*ft_new_path(char *path, char **env)
{
	char	*new_path;
	char	*tmp;
	char	**arr;

	new_path = NULL;
	tmp = ft_join_path(path, env);
	arr = ft_strsplit(tmp, '/');
	if (*arr != NULL)
		new_path = ft_new_from_arr(arr);
	ft_arrdel(arr);
	if (new_path != NULL)
	{
		free(tmp);
		return (new_path);
	}
	ft_del_slash(&tmp);
	return (tmp);
}
