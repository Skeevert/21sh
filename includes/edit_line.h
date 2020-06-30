/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_line.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladlenaskubis <vladlenaskubis@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:03:22 by sschmele          #+#    #+#             */
/*   Updated: 2020/03/28 01:22:11 by vladlenasku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# define TERMCAP_BUFF 	20
# define CMD_SIZE		100
# define NEW_LINE_SY	0x1
# define NEW_LINE_TE	0x2

/*
** @t_readline is for the whole readline part:
**
** @cmd is a command string printed by the user
** @pos - position of the cursor in the command-string
** @str_num - number of lines the command-string consists of
** @prompt_len - length of the prompt (invitation to enter the command)
** @cmd_buff_len - buffer of the cmd-line
** (can grow, after printing "Enter" is freed)
** @flag - the "working" variable
*/

typedef struct				s_readline
{
	char					*cmd;
	int						cmd_len;
	int						pos;
	int						pos_x;
	int						pos_y;
	int						str_num;
	int						cmd_buff_len;
	int						flag;
}							t_readline;

/*
** @t_action_stack is for the "ctrl-x ctrl-u" action:
**
** @cmd_b - the command string printed by the user before
** the last change (last action)
** @pos_b - position of the cursor in the command-string before
** the last change (last action)
** @num_b - number of lines the command-string consisted of before
** the last change (last action)
*/

typedef struct				s_action_stack
{
	char					*cmd_b;
	int						pos_b;
	int						num_b;
	struct s_action_stack	*next;
	struct s_action_stack	*prev;
}							t_action_stack;

t_readline					g_readline;
struct winsize				g_winsize;
struct termios				g_tty;

/*
** File line_edition_start.c
*/

int							interactive_shell(void);
int							readline_beg(void);
void						init_readline(void);
void						bzero_readline(void);
int							readline(void);

/*
** File sequence_route.c
*/

int							ctrl_seq(char c);
int							escape_seq(void);
int							escape_check(char **seq_base);
int							escape_funcs(int sequence_num);
int							incorrect_seq(void);

/*
** File prompts.c
*/

int							main_prompt(void);
int							heredoc_prompt(void);
int							other_prompt(void);
int							route_exit(void);

/*
** File terminal_and_termcap.c
*/

int							noncanonical(void);
int							canonical_back(void);
int							put_termcap(char *cap);
int							ft_print_int(int c);
int							put_cursor(char *cap, int x, int y);

/*
** File insert_char.c
*/

int							add_char(char c, int flag);
int							insert_char(char c);
int							front_insert_char(char c, int pos_x);
int							front_insert_newline(int *pos_x, int *pos_y,
								int *str_num, int *flag);
int							front_insert_till_end(int str_num_print);

/*
** File cursor_position.c
*/

int							posx_for_newline(int nl_pos);
int							return_cursor_to_position(int pos_old,
								char side);
int							front_move_char_right(int pos_x);
int							front_move_char_left(int pos_x);
int							setjmp_cursor(int *pos, int *pos_x,
								int *pos_y, int flag);

/*
** File undo_yank_call.c
*/

int							make_ctrl_x(void);
int							undo_wrap(void);
int							make_ctrl_p_wrap(void);
int							ctrlp_paste(int mode, char *yank);
int							yank_insert(char *yank_str, int len_yank);

/*
** File undo.c
*/

int							undo(int mode);
void						action_pull(t_action_stack **start,
								int *num);
void						action_alloc_management(t_action_stack **start,
								int mode);
int							action_add(t_action_stack **start,
								t_action_stack **end, int *num);
t_action_stack				*action_new(void);

/*
** File delete_keys.c
*/

int							backspace_process(void);
int							backspace_newline(char *swap, int len_swap);
int							delete_process(void);
int							clean_cmd(void);

/*
** File arrow_keys.c
*/

int							key_right_proc(void);
int							key_up_proc(void);
int							key_left_proc(void);
int							key_down_proc(void);

/*
** File jump_words.c
*/

int							escb_jump_word_left(void);
int							escf_jump_word_right(void);
char						*save_word(int *i, char *cmd, int pos);
char						*save_end(int pos_back);

/*
** File cut_line_parts.c
*/

int							ctrlk_cut_till_end(void);
int							ctrlu_cut_till_beg(void);
int							ctrlw_cut_till_word_beg(void);
int							escd_cut_till_word_end(void);

/*
** File jump_around_and_paste.c
*/

int             			jump_up(void);
int             			jump_down(void);
int							ctrlae_jump_home_end(char c);
int							ctrlp_paste(int mode, char *yank);
int							paste_insert(char *paste_str, int len_paste);

/*
** File history_proc.c
*/

void						init_hist_buff(void);
int							add_history(char *cmd);
int							add_history_eof_cmd(char *cmd, int flag);
int							scroll_hist_buffer(int num);

#endif
