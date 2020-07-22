/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh21.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:38:49 by sschmele          #+#    #+#             */
/*   Updated: 2020/07/22 13:47:36 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_H
# define SH21_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>
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

# include "errors_management.h"
# include "libft.h"
# include "help_lib.h"
# include "lexparser.h"
# include "edit_line.h"
# include "builtins.h"

# define 			MAX_HISTORY 500
# define			MAXDIRLEN 256
# define			EXIT_STATUS_LEN 10
# define 			VAR_BUFFER 120
# define			EXIT 21

/*
** Flags for shell_variables
*/

# define			ENV_VIS		0x1
# define			SET_VIS		0x2
# define			READONLY 	0x4

/*
** MAXDIR according to POSIX:  _POSIX_PATH_MAX
*/

# define			MAXDIR 256

typedef struct		s_prompt
{
	int				(*prompt_func)(void);
	int				prompt_len;
}					t_prompt;

/*
** @cmd is an array with commands (not separated by \n but
** separated as they came to lexparser)
** @len is the number of lines (commands) in the history
** @last is counter of the last command saved in the history
** @count is a line in cmd-array we are standing on after up or
** down key-sequences. After pressing "\n" counter is always
** @last + 1
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
** @AST is "*", @EQUAL = "=", @ENTER is "\n", @COMENT is "#",
** @BANG is "!", @COLON is ":",
** @GLUE is " " in DQUOTS, @TEXT is quoted symbol, @END_T is end of line
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
	BANG,
	COLON,
	GLUE,
	TEXT,
	END_T,
	SQUOTE_ANSI,
};

/*
** @g_envi - global variable with all the shell variables
** @g_var_size is the length of the @g_envi buffer
** @g_prompt is the function and the prompt valid
** @g_hist is the structure with the history valid for
** the shell session
*/

char				**g_envi;
int					g_var_size;
t_prompt			g_prompt;
t_history			g_hist;

/*
** File main.c
*/

int					noninteractive_shell(char **argv);
int					check_c_option(int argc, char **argv);

/*
** File global_vars_proc.c
*/

char				*find_env_value(char *str);
int					find_in_variable(int *j, char *name);
int					form_local_envir(char ***arr, int size);
int					add_new_env(char *name);
int					change_env_value(char *new_val, int i);

/*
** File global_variables.c
*/

int					create_env(void);
int					save_environment_variable(int num);
int					save_shell_variable(int num);
int					exit_status_variables(int status);
int					save_readonly_variable(int num);

/*
** File signals.c
*/

int					signals_define(int from);
void				signal_ctrl_c_readline(int sig);
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
