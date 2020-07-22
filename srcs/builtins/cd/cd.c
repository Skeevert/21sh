/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 18:39:16 by rbednar           #+#    #+#             */
/*   Updated: 2020/07/22 22:15:34 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "builtins.h"

void	cd_free(char **cd_cur)
{
	if (*cd_cur)
	{
		free(*cd_cur);
		*cd_cur = NULL;
	}
}

void	ft_values(t_ltree *pos, char **cd_cur)
{
	int	i;
	int	j;

	i = find_in_variables(pos->envir, &j, "PWD");
	if (i == -1)
		*cd_cur = getcwd(NULL, 0);
	else
		*cd_cur = ft_strdup(pos->envir[i] + j);
}

void	ft_change_curpath(char *path, char **cd_cur)
{
	free(*cd_cur);
	if (!path)
		*cd_cur = NULL;
	else
		*cd_cur = ft_strdup(path);
}

int		ft_error(char *name, int err)
{
	char	*tmp;

	tmp = ft_strdup("cd: ");
	if (name)
		tmp = ft_strrejoin(tmp, name);
	if (err == 1)
		tmp = ft_strrejoin(tmp, ": string not in pwd");
	else if (err == 2)
		tmp = ft_strrejoin(tmp, ": no such file or directory");
	else if (err == 3)
		tmp = ft_strrejoin(tmp, ": permission denied");
	else if (err == 4)
		tmp = ft_strrejoin(tmp, ": not a directory");
	else if (err == 5)
		tmp = ft_strrejoin(tmp, "too many arguments");
	else if (err == 6)
		tmp = ft_strrejoin(tmp, "OLDPWD not set");
	errno(ERR_VARIABLE, ERR_VAR_CD, tmp);
	free(tmp);
	return (1);
}

int		btin_cd(t_ltree *pos)
{
	char	*cd_cur;
	char	*arg;

	ft_values(pos, &cd_cur);
	if (ft_valid_cd(pos, 1))
	{
		cd_free(&cd_cur);
		return (1);
	}
	arg = pos->ar_v[1] ? pos->ar_v[1] : NULL;
	if (ft_cd_pars(arg, pos))
	{
		cd_free(&cd_cur);
		return (1);
	}
	cd_free(&cd_cur);
	return (0);
}
