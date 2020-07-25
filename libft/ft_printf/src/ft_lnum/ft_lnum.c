/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:03:00 by rbednar           #+#    #+#             */
/*   Updated: 2020/05/29 22:13:44 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_lnum_new(t_lnum *a)
{
	int i;

	i = -1;
	a->size = 0;
	while (++i < DOTA_S)
		a->lnum[i] = 0;
}

void			ft_lnum_plus(t_lnum *a, t_lnum b)
{
	int		carry;
	int		i;

	i = 0;
	carry = 0;
	while (i < ft_max(a->size, b.size) + 1 || carry)
	{
		if (i == a->size + 1)
			a->size++;
		a->lnum[i] += carry + (i < (b.size + 1) ? b.lnum[i] : 0);
		carry = a->lnum[i] >= BASE_INT;
		if (carry)
			a->lnum[i] -= BASE_INT;
		i++;
	}
}

void			ft_lnum_plus2(t_lnum *a, int b)
{
	a->lnum[0] += b;
}

void			ft_lnum_mul(t_lnum *a, int b)
{
	int			carry;
	long long	cur;
	int			i;

	carry = 0;
	i = 0;
	while (i < a->size + 1 || carry)
	{
		if (i == a->size + 1)
			a->size++;
		cur = carry + a->lnum[i] * 1ll * b;
		a->lnum[i] = (int)(cur % BASE_INT);
		carry = (int)(cur / BASE_INT);
		i++;
	}
	while (a->size > 0 && a->lnum[a->size] == 0)
		a->size--;
}
