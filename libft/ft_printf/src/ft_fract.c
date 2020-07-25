/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fract.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:01:42 by rbednar           #+#    #+#             */
/*   Updated: 2019/09/20 18:01:46 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	*ft_print_part(t_lnum res, char flag)
{
	int		i;
	char	*res_c;
	char	*tmp;
	char	*tmp_1;

	i = res.size;
	if (flag == 'f')
		i--;
	res_c = NULL;
	while (i >= 0)
	{
		tmp = ft_itoa_pf(res.lnum[i]);
		tmp_1 = res_c;
		res_c = ft_strjoin_pf(res_c, tmp);
		free(tmp);
		free(tmp_1);
		i--;
	}
	return (res_c);
}

static char	*ft_main_p(int shift, unsigned long long m)
{
	t_lnum	mi;
	t_lnum	res;

	ft_lnum_new(&mi);
	ft_lnum_new(&res);
	ft_lnum_plus2(&mi, 1);
	while (shift)
	{
		if ((m & (1ull << (64ull - (long)shift--))) && shift <= 63)
			ft_lnum_plus(&res, mi);
		ft_lnum_mul(&mi, 2);
	}
	return (ft_print_part(res, 'm'));
}

static char	*ft_fract(int shift, unsigned long long m)
{
	t_lnum		fi;
	t_lnum		res;

	ft_lnum_new(&fi);
	ft_lnum_new(&res);
	ft_lnum_plus2(&res, 1);
	ft_lnum_plus2(&fi, 1);
	while (shift)
	{
		if ((m & (1ull << (shift-- - 64ull))) && shift <= 64)
			ft_lnum_plus(&res, fi);
		ft_lnum_mul(&res, 10);
		ft_lnum_mul(&fi, 5);
	}
	return (ft_print_part(res, 'f'));
}

void		ft_bigint_ulong(int e,\
				unsigned long long m, char **main, char **frac)
{
	*main = ft_itoa_pf(m >> (63 - (e - 16383)));
	*frac = ft_fract(63 - (e - 16383), m);
}

void		ft_max_min_bigint(int e,\
				unsigned long long m, char **main, char **frac)
{
	if (e - 16383 < 0)
	{
		*main = ft_itoa_pf(0);
		*frac = ft_fract(63 - (e - 16383), m);
	}
	else if (e - 16383 > 63)
	{
		*main = ft_main_p(e - 16383 + 1, m);
		*frac = ft_itoa_pf(0);
	}
}
