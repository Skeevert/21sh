/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldoublecheck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:02:25 by rbednar           #+#    #+#             */
/*   Updated: 2019/09/20 18:02:27 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_zero_m_e(char **main, char **frac)
{
	*main = ft_itoa_pf(0);
	*frac = ft_itoa_pf(0);
}

void	ft_len_frac_more_prec(int tmp, int prec, char **frac)
{
	char			*tmp_c;
	char			*tmp_prec;

	tmp_c = ft_memnew_pf(prec - tmp, '0');
	tmp_prec = *frac;
	*frac = ft_strjoin_pf(tmp_prec, tmp_c);
	free(tmp_prec);
	free(tmp_c);
}
