/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbednar <rbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:02:01 by rbednar           #+#    #+#             */
/*   Updated: 2019/09/20 18:02:04 by rbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_un(char *main, char *s)
{
	char	*tmp_c;

	tmp_c = main;
	if (*s == '-')
		main = ft_strjoin_pf(s, main);
	else
		main = ft_strjoin_pf(main, s);
	free(tmp_c);
	return (main);
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
