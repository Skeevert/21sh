/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladlenaskubis <vladlenaskubis@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:38:49 by sschmele          #+#    #+#             */
/*   Updated: 2020/04/07 17:28:49 by vladlenasku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_H
# define SH21_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <pwd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h> //DELETE

# include "errors_management.h"
# include "libft.h"
# include "help_lib.h"
# include "lexparser.h"
# include "edit_line.h"
# include "builtins.h"

# include "ft_printf.h" //If not used, delete

# define 			MAX_HISTORY 500
# define			MAXDIRLEN 256
# define			EXIT_STATUS_LEN 10
# define 			VAR_BUFFER 50
# define			EXIT 21

typedef struct		s_prompt
{
	int				(*prompt_func)(void);
	int				prompt_len;
}					t_prompt;

/*
** @hist is an array with commands (not separated by \n but
** separated as they came to lexparser)
** @len is the number of lines (commands) in the history
** @last is counter of the last command saved in the history
** @start is a counter from which command from history file we start to
** fill out buffer - not to rewrite the whole buffer to the file but to add
** We need all
*/

typedef struct		s_history
{
	char			**cmd;
	int				len;
	int				count;
	int				last;
}					t_history;

/*
** @BSLASH is "\", @SCOLON is ";", @AND is "&", @DQUOTE is '"',
** @SQUOTE is "'", @OPAREN is "(", @CPAREN is ")", @OBRACKET is "["
** @CBRACKET is "]", @OBRACE is "{", CBRACE is "}", @DOLLAR is "$",
** @TILDA is "~", @PIPE is "|", @GTHAN is ">", @LTHAN is "<",
** @AST is "*", @EQUAL = "=", @ENTER is "\n", @COMENT is "#"
*/

enum				e_techline
{
	WORD_P = 1,
	SPACE ,
	BSLASH,
	SCOLON,
	AND,
	DQUOTE,
	SQUOTE,
	OPAREN,
	CPAREN,
	OBRACKET,
	CBRACKET,
	OBRACE,
	CBRACE,
	DOLLAR,
	TILDA,
	PIPE,
	GTHAN,
	LTHAN,
	AST,
	EQUAL,
	ENTER,
	COMENT,
	GLUE,
	TEXT,
	END_T
};

/*
** @g_env - global variable with (char **environ) parameters
** @g_sh_var - shell variables
*/

char				**g_env;
char				**g_rdovar;
char				**g_lovar;
int					g_arrsize;
t_prompt			g_prompt;
t_history			g_hist;

/*
** File main.c
*/

int					noninteractive_shell(int argc, char **argv);
int					check_c_option(int argc, char **argv);

/*
** File global_variables.c
*/

int					prepare_environ(void);
int					prepare_readonly(void);
int					prepare_local(void);
int                 var_exit_status(int status);
char				**init_exec_environ(void);

/*
** File global_vars_proc.c
*/

int					add_environ(char *add);
int					add_local(char *add);
int					add_environ_exec(char ***array, char **add);
int					change_global_variable(char *find, char *insert,
						char **array);
int					variables_search(char **arr, int *j, char *name);

/*
** File signals.c
*/

int					signals_define(int from);
void				signal_ctrl_c_readline(int sig);
void				signal_ctrl_c_parser(int sig);
void				signal_screen(int sig);

/*
** File errno.c
*/

int					errno(int status, int errtype, char *str);
int					errtypes_first(int errtype, char *name);
int					errtypes_second(int errtype, char *name);
int					exit_status_variable(void);

/*
** File detructor.c
*/

int					destruct_globals(void);
int					destruct_parser(void);

#endif
