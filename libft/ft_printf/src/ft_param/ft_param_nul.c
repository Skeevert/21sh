/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_nul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <fcraydle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:42:20 by fcraydle          #+#    #+#             */
/*   Updated: 2019/09/20 17:42:20 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void				ft_param_nul(t_param *param)
{
	param->precision = -1;
	param->width = 0;
	param->minus = 0;
	param->plus = 0;
	param->zero = 0;
	param->hasht = 0;
	param->space = 0;
	param->length = 0;
}
