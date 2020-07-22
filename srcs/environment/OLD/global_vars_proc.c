#include "sh21.h"

/*
** Adding new to @g_env (shell environment)
** Can be done only with builtins export (export FOO=bar)
*/

int		add_environ(char *add)
{
	int		num;
	
	num = 0;
	while (g_env[num])
		num++;
	if (num == g_arrsize)
	{
		g_env = ft_realloc_array(&g_env, g_arrsize, g_arrsize * 2);
		g_lovar = ft_realloc_array(&g_lovar, g_arrsize, g_arrsize * 2);
		g_arrsize *= 2;
	}
	g_env[num] = ft_strdup(add);
	return (0);
}

int		add_local(char *add)
{
	int		num;
	
	num = 0;
	while (g_lovar[num])
		num++;
	if (num == g_arrsize)
	{
		g_env = ft_realloc_array(&g_env, g_arrsize, g_arrsize * 2);
		g_lovar = ft_realloc_array(&g_lovar, g_arrsize, g_arrsize * 2);
		g_arrsize *= 2;
	}
	g_lovar[num] = add;
	return (0);
}

/*
** Adding new variable to the environ of the command to be executed
** First we try to find if it already exists and insert if it is found
** Then we add if the @add is a new variable
*/

int		add_environ_exec(char ***array, char **add)
{
	int		i;
	int		li;
	int		sy;
	char	*find;

	i = 0;
	find = ft_strndup(*add, ft_strrchri(*add, '='));
	if ((li = variable_search(g_env, &sy, find)) != -1)
		return (change_global_variable(find, *add,	&g_env[li]));
	else
	{
		while (array[0][i])
			i++;
		if (i == g_arrsize)
		{
			ft_realloc_array(array, g_arrsize, g_arrsize * 2);
			g_env = ft_realloc_array(&g_env, g_arrsize, g_arrsize * 2);
			g_lovar = ft_realloc_array(&g_lovar, g_arrsize, g_arrsize * 2);
			g_arrsize *= 2;
		}
		array[0][i] = *add;
	}
	return (0);
}

int		change_global_variable(char *find, char *insert,
			char **array)
{
	free(find);
	free(*array);
	*array = insert;
	return (0);
}

int		variable_search(char **arr, int *j, char *name)
{
	int		i;
	int		tmp;
	int		len_name;

	i = 0;
	if (!arr)
		return (-1);
	len_name = ft_strlen(name);
	while (arr[i])
	{
		tmp = ft_strchri(arr[i], '=');
		if (ft_strncmp(arr[i], name, len_name) == 0)
		{
			*j = tmp + 1;
			return (i);
		}
		i++;
	}
	return (-1);
}