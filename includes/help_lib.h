/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_lib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 20:46:22 by sschmele          #+#    #+#             */
/*   Updated: 2020/07/22 20:34:04 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELP_LIB_H
# define HELP_LIB_H

typedef struct			s_stack
{
	int					data;
	struct s_stack		*next;
}						t_stack;

void					*ft_realloc(void *subj, size_t len_subj,
							size_t len, size_t len_needed);
void					*ft_xmalloc(size_t size);
int						ft_issign(char c);
char					*ft_straddsy(char *dest, char sy);
int						ft_strrchri(char *s, int c);
void					ft_add_list_to_end(t_list **start,
							t_list *new_list);
char					**ft_realloc_array(char ***subj, int len_subj,
							int len_needed);
void					ft_lstclear(t_list **begin_list);
t_list					*ft_lstlast(t_list **begin_list);
size_t					ft_count_words_i(char const *s, char c,
							size_t len);
size_t					ft_strlenchri(const char *s, char c);
int						ft_strchrcmp(const char *s1, const char *s2,
							char x);
void					ft_arrdel(char **arr);
void					ft_arrshift(char **arr, int size, int shift);
void					**ft_memrealloc_array(void ***subj, int len_subj,
						int len_needed);
void					ft_delelem_array(char ***array, int len,
							int start, int num);
char					*ft_find_token_sep(char *str);
char					*ft_itoa(int n);
char					*ft_strdup(const char *s1);
char					*ft_strjoin(char const *s1, char const *s2);
void					ft_strshift(char *str, int shift);
char					*ft_strndup(const char *s1, size_t n);
char					*ft_strrejoin(char *s1, char *s2);
char					**ft_strsplit(char const *s, char c);

int						ft_ishexdigit(char c);
int						ft_isoctdigit(char c);
int						ft_atoi_base(char *str, int str_base);

/*
** Folder stack_structure______________________________________________________
*/

/*
** User makes his own safety for the pop-stack function because it returns data
** that is int and it is impossible to return some "wrong" int to show the fail
** Maybe one day I rewrite.
*/

t_stack					*ft_init_stack(void);
int						ft_pop_stack(t_stack **head);
int						ft_push_stack(t_stack **head, int data);
void					ft_clear_stack(t_stack **head);
int						ft_last_stack(t_stack **head);

#endif
