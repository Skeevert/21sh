#include "sh21.h"
#include "lexparser.h"

static char	*g_sign[23] = {
	"\0", "\0", " ", "\\", ";", "&", "\"", "\'", "(", ")", "[", "]",
	"{", "}", "$", "~", "|", ">", "<", "*", "=", "\n", "#"};

int		nullify_error(t_stack **stack)
{
	if ((*stack)->data == DOLLAR)
			ft_pop_stack(stack);
		if ((*stack)->data == DQUOTE || (*stack)->data == SQUOTE ||
		(*stack)->data == OPAREN || (*stack)->data == OBRACE ||
		(*stack)->data == BSLASH)
			g_prompt.prompt_func = other_prompt;
		if (((*stack)->data == EOF ||
				ft_atoi(find_env_value("NONINTERACTIVE_MODE"))) &&
				g_prompt.prompt_func != heredoc_prompt)
		{
			g_prompt.prompt_func = main_prompt;
			errno(ERR_SYNTAX, ERR_SQUOTE, g_sign[(*stack)->data]);
		}
		ft_clear_stack(stack);
		return (EXIT);
}
