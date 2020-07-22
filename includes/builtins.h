/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladlenaskubis <vladlenaskubis@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:45:45 by sschmele          #+#    #+#             */
/*   Updated: 2020/03/25 17:08:25 by vladlenasku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define ECHO_N 	0x1
# define ECHO_E		0x2
# define ECHO_UP_E	0x4

# define CD_STRING_N_PWD 1
# define CD_N_FILE_DIR 2
# define CD_N_PERMISSION 3
# define CD_NOT_DIR 4
# define CD_MANY_ARGS 5
# define CD_OLDPWD_NS 6

# define BUILTINS_NUM 7

typedef struct	s_ec
{
	int			e;
	int			n;
	int			up_e;
}				t_ec;

int				btin_exit(t_ltree *pos);

/*
** Folder cd, file cd.c
*/

int				btin_cd(t_ltree *pos);
void			cd_free(char **cd_cur);
int				ft_error(char *name, int en);
void			ft_change_curpath(char *path, char **cd_cur);
void			ft_values(t_ltree *pos, char **cd_cur);

/*
** File cd_parser.c
*/

int				ft_cd_pars(char *path, t_ltree *pos);
int				ft_cd_env(char *path, t_ltree *pos);
int				ft_valid_cd(t_ltree *pos, int i);

/*
** File cd_change_path.c
*/

int				ft_change_path(char **path, t_ltree *pos);
void			ft_change_pwd(char **path, t_ltree *pos);
int				ft_to_dir(char *path);
int				ft_del_slash(char **str);

/*
** File cd_new_path.c
*/

char			*ft_new_path(char *path, char **env);
char			*ft_join_path(char *path, char **env);
char			*ft_new_from_arr(char **arr);
void			ft_del_dots(char **arr);
void			ft_del_prev(char **arr, int i);

/*
** File set.c
*/

int				btin_set(void);

/*
** File unset.c
*/

int				btin_unset(t_ltree *pos);

/*
** File echo.c
*/

int				btin_echo(t_ltree *pos);


#endif
