#include "sh21.h"

/*
** Environmental shell variables - are dinamic, exist within the session,
** the function save_environment_variables saves the parent process
** environ to 21sh @g_envi.
**
** Can be changed by assignment (HOME=aaa)
** or export (export HOME=aaa)
** and a new line added by export-builtin (export FOO=bar)
*/

int					save_environment_variable(int num)
{
	extern char		**environ;
	int				i;

	i = 0;
	while (environ[i])
	{
		if (num >= g_var_size || num + 1 >= g_var_size)
		{
			g_envi = ft_realloc_array(&g_envi, g_var_size, g_var_size * 2);
			g_var_size *= 2;
		}
		g_envi[num] = (char*)ft_xmalloc(((ft_strlen(environ[i]) + 2) * (sizeof(char))));
		ft_strcpy(g_envi[num] + 1, environ[i]);
		g_envi[num][0] |= ENV_VIS;
		g_envi[num][0] |= SET_VIS;
		num++;
		i++;
	}
	return (num);
}

/*
** Shell readonly variables - always static, array @g_envi with flag READONLY
**
** Can be only read by the user and corrected only within 21sh program
*/

char				*ft_add_rdovar(char *first, char *scnd, int flag)
{
	char	*res;

	res = (char*)ft_xmalloc((ft_strlen(first) + ft_strlen(scnd) + 2) * (sizeof(char)));
	ft_strcpy(res + 1, first);
	if (scnd)
		ft_strcpy(res + ft_strlen(first) + 1, scnd);
	if (flag != 2)
		res[0] |= READONLY;
	if (flag != 1)
		res[0] |= SET_VIS;
	return (res);
}

int					save_readonly_variable(int num)
{
	char	*tmp;

	g_envi[num++] = ft_add_rdovar("?=0", NULL, 1);
	g_envi[num++] = ft_add_rdovar("0=21sh", NULL, 1);
	g_envi[num++] = ft_add_rdovar("NONINTERACTIVE_MODE=0", NULL, 1);
	tmp = getcwd(NULL, MAXDIR);
	g_envi[num++] = ft_add_rdovar("21SH=", tmp, 0);
	free(tmp);
	tmp = ft_itoa(getuid());
	g_envi[num++] = ft_add_rdovar("UID=", tmp, 0);
	free(tmp);
	tmp = ft_itoa(geteuid());
	g_envi[num++] = ft_add_rdovar("EUID=", tmp, 0);
	free(tmp);
	tmp = ft_itoa(getppid());
	g_envi[num++] = ft_add_rdovar("PPID=", tmp, 0);
	free(tmp);
	tmp = ft_itoa(getpid());
    g_envi[num++] = ft_add_rdovar("$=", tmp, 1);
    free(tmp);
	return (num);
}

/*
** Shell local variables - dinamic, exist within the session
** @g_envi with flag SET_VIS
** 
** Can be added and changed by assignment (fuu=bar)
** And if already exists in @g_envi and
** is used in export (export fuu=bbb),
** the variable starts to be visible in env by flag ENV_VIS
*/

int					create_env(void)
{
	int		num;
	char	*tmp;

	g_envi = (char **)ft_xmalloc(VAR_BUFFER * sizeof(char*));
	num = save_readonly_variable(0);
	num = save_environment_variable(num);
	change_pwd_value((tmp = getcwd(NULL, MAXDIR)));
	change_oldpwd_value(tmp);
	free(tmp);
	return (0);
}

int                 var_exit_status(int status)
{
    char            *tmp;
	char			*final;
	int				i;
	int				j;

    tmp = ft_itoa(status);
	i = variable_search(&j, "?");
	final = ft_strjoin("?=", tmp);
	change_env_value(final, i);
	free(final);
    free(tmp);
    return (0);
}
