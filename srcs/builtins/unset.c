#include "sh21.h"
#include "builtins.h"

static int	unset_from_array(char **arr, t_ltree *pos, int i)
{
	if (i == 0)
	{
		free(arr[i]);
		arr[0] = NULL;
		return (0);
	}
	free(arr[i]);
	arr[i] = arr[i + 1];
	i++;
	while (arr[i])
	{
		arr[i] = arr[i + 1];
		i++;
	}
	return (0);
}

int			btin_unset(t_ltree *pos)
{
	int		unused;
	int		j;
	int		i;

	i = 1;
	while (i < pos->ar_c)
	{
		if ((j = variables_search(g_env, &unused, pos->ar_v[i])) != -1)
			unset_from_array(g_env, pos, j);
		if ((j = variables_search(g_lovar, &unused, pos->ar_v[i])) != -1)	
			unset_from_array(g_lovar, pos, j);
		i++;
	}
	return (0);	
}