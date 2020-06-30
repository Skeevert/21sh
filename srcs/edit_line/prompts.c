#include "sh21.h"
#include "edit_line.h"

int				main_prompt(void)
{
	const char	*prompt = "21sh";

	ft_putstr_fd("\033[1;33m", STDOUT_FILENO);
	ft_putstr_fd(prompt, STDOUT_FILENO);
	ft_putstr_fd("\033[0m", STDOUT_FILENO);
	ft_putstr_fd("> ", STDOUT_FILENO);
	g_prompt.prompt_len = ft_strlen(prompt) + 2;
	return (0);
}

int				heredoc_prompt(void)
{
	ft_putstr_fd("heredoc> ", STDOUT_FILENO);
	g_prompt.prompt_len = 9;
	return (0);
}

int				other_prompt(void)
{
	ft_putstr_fd("> ", STDOUT_FILENO);
	g_prompt.prompt_len = 2;
	return (0);
}

int				route_exit(void)
{
	if (g_prompt.prompt_func == main_prompt)
	{
		action_alloc_management(NULL, 1);
		canonical_back();
		free(g_readline.cmd);
		btin_exit(SUCCESS);
	}
	if (g_prompt.prompt_func != main_prompt)
	{
		g_readline.cmd = ft_straddsy(g_readline.cmd, EOF);
		return (EXIT);
	}
	return (0);
}