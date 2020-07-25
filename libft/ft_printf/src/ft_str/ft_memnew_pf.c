/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnew_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcraydle <fcraydle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:43:35 by fcraydle          #+#    #+#             */
/*   Updated: 2019/09/20 17:43:35 by fcraydle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

char	*ft_memnew_pf(size_t i, int lett)
{
	return (ft_memset_pf(ft_strnew_pf(i), lett, i));
}
