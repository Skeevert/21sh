#include "sh21.h"
#include "edit_line.h"
#define ESC_LEN 10

int			ctrl_seq(char c)
{
	int		exit;

	exit = 0;
	if (c == '\013')
		exit = ctrlk_cut_till_end();
	else if (c == '\025')
		exit = ctrlu_cut_till_beg();
	else if (c == '\027')
		exit = ctrlw_cut_till_word_beg();
	else if (c == '\001' || c == '\005')
		exit = ctrlae_jump_home_end(c);
	else if (c == '\004')
		exit = delete_process();
	else if (c == 127 || c == '\010')
		exit = backspace_process();
	else if (c == '\030')
		exit = make_ctrl_x();
	else if (c == '\020')
		exit = make_ctrl_p_wrap();
	return (exit);
}

/*
** We have already read \033, so seq_base is formed without it
** [C -- KEY_RIGHT
** [A -- KEY_UP
** [D -- KEY_LEFT
** [B -- KEY_DOWN
** r -- CLEAR LINE
** [3~ -- DELETE CHAR
** b -- BACK ONE WORD
** f -- FORWARD ONE WORD
** d -- DELETE UNTILL THE NEXT WORD
*/

int			escape_seq(void)
{
	char	*seq_base[ESC_LEN];

	seq_base[0] = "[C";
	seq_base[1] = "[A";
	seq_base[2] = "[D";
	seq_base[3] = "[B";
	seq_base[4] = "[3~";
	seq_base[5] = "b";
	seq_base[6] = "f";
	seq_base[7] = "d";
	seq_base[8] = "[1;5A";
	seq_base[9] = "[1;5B";
	return (escape_check(seq_base));
}

int			escape_check(char **seq_base)
{
	int		i;
	char	buff[16];
	int		count;

	i = 0;
	ft_bzero(buff, 16);
	while (read(0, buff + i, 1))
	{
		count = 0;
		while (count < ESC_LEN)
		{
			if (!ft_strncmp(buff, seq_base[count], i + 1))
				break ;
			count++;
		}
		if (count == ESC_LEN)
			return (incorrect_seq());
		if (!ft_strncmp(buff, seq_base[count], ft_strlen(seq_base[count]) + 1))
			return (escape_funcs(count));
		i++;
	}
	return (0);
}

/*
** Function pointer array, should return function call
*/

int			escape_funcs(int seq_num)
{
	int		(*seq_func[ESC_LEN])(void);

	seq_func[0] = key_right_proc;
	seq_func[1] = key_up_proc;
	seq_func[2] = key_left_proc;
	seq_func[3] = key_down_proc;
	seq_func[4] = delete_process;
	seq_func[5] = escb_jump_word_left;
	seq_func[6] = escf_jump_word_right;
	seq_func[7] = escd_cut_till_word_end;
	seq_func[8] = jump_up;
	seq_func[9] = jump_down;
	return ((*seq_func[seq_num])());
}

/*
** Should beep and do nothing - bell
*/

int			incorrect_seq(void)
{
	put_termcap("bl");
	return (1);
}