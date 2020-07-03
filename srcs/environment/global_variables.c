#include "sh21.h"

/*
** Environmental shell variables - are dinamic, exist within the session,
** the function prepare_environ saves the parent process
** environ to 21sh @g_env.
**
** Can be changed by assignment (HOME=aaa)
** or export (export HOME=aaa)
** and a new line added by export-builtins (export FOO=bar)
*/

int		prepare_environ(void)
{
	extern char		**environ;
	int				num;

	num = 0;
	g_env = (char**)ft_xmalloc((g_arrsize + 1) * (sizeof(char*)));
	while (environ[num])
	{
		if (num == g_arrsize)
		{
			g_env = ft_realloc_array(&g_env, g_arrsize, g_arrsize * 2);
			g_arrsize *= 2;
		}
		g_env[num] = ft_strdup(environ[num]);
		num++;
	};
	return (0);
}

int		prepare_readonly(void)
{
	int				len;
	char			*temp;

	len = 4;
	g_rdovar = (char**)ft_xmalloc((len + 1) * (sizeof(char*)));
	g_rdovar[0] = (char*)ft_xmalloc(sizeof(char) * EXIT_STATUS_LEN);
	g_rdovar[0] = ft_strcpy(g_rdovar[0], "?=0");
	g_rdovar[1] = ft_strdup("NONINTERACTIVE_MODE=0");
	temp = getcwd(NULL, MAXDIRLEN);
	g_rdovar[2] = ft_strjoin("PWD=", temp);
	free(temp);
	temp = getcwd(NULL, MAXDIRLEN);
	g_rdovar[3] = ft_strjoin("OLDPWD=", temp);
	free(temp);
	return (0);
}

/*
** Shell local variables - dinamic, exist within the session
** @g_lovar in 21sh
** 
** Can be added and changed by assignment (fuu=bar)
** And if already exists in @g_lovar and
** is used in export (export fuu=bbb),
** the variable starts to be visible in @g_env (by env command)
*/

int		prepare_local(void)
{

	g_lovar = (char**)ft_xmalloc((g_arrsize + 1) * (sizeof(char*)));
	return (0);
}

int		var_exit_status(int status)
{
	char			*tmp;
	char			*final;

	tmp = ft_itoa(status);
	final = ft_strjoin("?=", tmp);
	free(g_rdovar[0]);
	g_rdovar[0] = final;
	free(tmp);
	return (0);
}

char	**init_exec_environ(void)
{
	char			**envir;
	int				i;

	envir = (char**)ft_xmalloc(sizeof(char*) * (g_arrsize + 1));
	i = 0;
	while(g_env[i])
	{
		envir[i] = ft_strdup(g_env[i]);
		i++;
	}
	return (envir);
}