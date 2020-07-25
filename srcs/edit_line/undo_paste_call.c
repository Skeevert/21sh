/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo_paste_call.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshawand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 17:35:55 by hshawand          #+#    #+#             */
/*   Updated: 2020/07/25 17:35:57 by hshawand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"
#include "edit_line.h"

int			make_ctrl_x(void)
{
	char			next;

	read(1, &next, 1);
	if (next == '\025')
		undo(1);
	else
		incorrect_seq();
	return (0);
}

int			undo_wrap(void)
{
	return (undo(1));
}

int			make_ctrl_p_wrap(void)
{
	return (ctrlp_paste(1, NULL));
}
