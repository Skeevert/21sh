/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_and_termcap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:35:05 by hshawand          #+#    #+#             */
/*   Updated: 2020/07/25 17:35:06 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "edit_line.h"

int		noncanonical(void)
{
	struct termios	tty;

	if (tcgetattr(STDIN_FILENO, &tty) < 0)
		return (-1);
	g_tty = tty;
	tty.c_lflag &= ~(ICANON | ECHO);
	tty.c_cc[VMIN] = 1;
	tty.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &tty) < 0)
		return (-1);
	return (0);
}

int		canonical_back(void)
{
	if (tcsetattr(STDIN_FILENO, TCSANOW, &g_tty) != 0)
	{
		errno(ERR_TERMINAL, 0, NULL);
		free(g_readline.cmd);
		destruct_globals();
		exit(ERR_TERMINAL);
	}
	return (0);
}

int		ft_print_int(int c)
{
	return (write(1, &c, 1));
}

int		put_termcap(char *code)
{
	char		buff[TERMCAP_BUFF];
	char		*ptr;

	ptr = buff;
	tputs(tgetstr(code, &ptr), 1, ft_print_int);
	ptr = buff;
	ft_bzero(ptr, TERMCAP_BUFF);
	return (0);
}

int		put_cursor(char *code, int x, int y)
{
	char		buff[TERMCAP_BUFF];
	char		*ptr;

	ptr = buff;
	tputs(tgoto(tgetstr(code, &ptr), x, y), 1, ft_print_int);
	ptr = buff;
	ft_bzero(ptr, TERMCAP_BUFF);
	return (0);
}
