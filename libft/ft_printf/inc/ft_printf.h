/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:40:12 by fcraydle          #+#    #+#             */
/*   Updated: 2020/06/08 17:47:23 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# define MAX_INT 922337203685477580
# define BUF_SIZE 1000
# define BASE_INT 10
# define DOTA_S 10000

typedef	__uint128_t	t_uint128;

typedef struct		s_param
{
	unsigned char	length;
	char			minus;
	char			plus;
	char			zero;
	char			hasht;
	char			space;
	int				width;
	int				precision;
}					t_param;

int					ft_param_add(t_param *new, char **str, va_list ap);
void				ft_param_nul(t_param *param);

typedef struct		s_buf
{
	size_t			top;
	size_t			size;
	int				err;
	char			*buf;
}					t_buf;

t_buf				*ft_buf_new(t_buf *new);
void				ft_buf_add_c(t_buf *new, char c);
void				ft_buf_add_s(t_buf *new, char *str, int flag);
void				ft_buf_add_ns(t_buf *new, char *str, size_t n,
						int flag);
int					ft_do_buf_empty(t_buf *buf);

typedef struct		s_lnum
{
	unsigned char	lnum[DOTA_S];
	int				size;
}					t_lnum;

void				ft_lnum_new(t_lnum *a);
void				ft_lnum_plus(t_lnum *a, t_lnum b);
void				ft_lnum_plus2(t_lnum *a, int b);
void				ft_lnum_mul(t_lnum *a, int b);

int					ft_printf(char *str, ...);
void				ft_percent(va_list ap, char **str,
						t_param list, t_buf *buf);

char				*ft_strnew_pf(size_t size);
int					ft_write_to_buff(unsigned long long c, char *str);
size_t				ft_strlen_pf(const char *s);
int					ft_num_dig(uintmax_t n, int base);
void				*ft_memset_pf(void *b, int c, size_t len);
char				*ft_memnew_pf(size_t i, int lett);
char				*ft_strjoin_pf(char *s1, char *s2);
char				*ft_strndup_pf(const char *s1, size_t n);
char				*ft_un(char *main, char *s);
int					ft_max(int a, int b);

void				ft_c(t_param list, char c, t_buf *buf);
void				ft_s(t_param list, char *s, t_buf *buf);
void				ft_p(t_param list, void *ptr, t_buf *buf);
void				ft_d(t_param list, va_list ap, t_buf *buf);
void				ft_d_up(t_param list, va_list ap, t_buf *buf);
void				ft_u(t_param list, va_list ap, t_buf *buf);
void				ft_u_up(t_param list, va_list ap, t_buf *buf);
void				ft_o(t_param list, va_list ap, t_buf *buf);
void				ft_o_up(t_param list, va_list ap, t_buf *buf);
void				ft_prec_neg_null(char *str, t_param list, t_buf *buf);
void				ft_prec_pos_null(t_param list, t_buf *buf);
void				ft_minus_pos_null(t_param list, int tmp, t_buf *buf);
void				ft_minus_neg_null(t_param list, int tmp, t_buf *buf);
void				ft_prcnt(t_param list, t_buf *buf);
void				ft_x_up(t_param list, va_list ap, t_buf *buf);
void				ft_x(t_param list, va_list ap, t_buf *buf);
void				ft_f(t_param list, va_list ap, t_buf *buf);
void				ft_f_up(t_param list, va_list ap, t_buf *buf);
char				*ft_float_f(long double f, int precision);
char				*ft_colours(char *str, t_buf *buf);
void				ft_zero_m_e(char **main, char **frac);
void				ft_len_frac_more_prec(int tmp, int prec, char **frac);
void				ft_bigint_ulong(int e,\
						unsigned long long m, char **main, char **frac);
void				ft_max_min_bigint(int e,\
						unsigned long long m, char **main, char **frac);

int					ft_atoi_pf(const char *str);
char				*ft_itoa_pf(long long n);
char				*ft_itoa_base(long long n, int base);
char				*ft_itoa_base_ll(uintmax_t n, int base);

#endif
