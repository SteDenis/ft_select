/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:34:06 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/08 10:41:14 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_select.h"

static int		interpreter(t_term *term, char buff[])
{
	if (DEL)
	{
		if (del_elem(&term))
			return (1);
	}
	else if (ISARROW)
		move_cursor(term, buff);
	else if (SUPPR)
	{
		if (del_elem(&term))
			return (1);
	}
	else if (CTRLR)
		search_items(term);
	else if (SPACE)
		select_item(term);
	else if (RETURN)
		return (1);
	return (0);
}

void		loop_select(t_term *term)
{
	char buff[7];

	calculate_start_print(term);
	print_list_choices(term);
	while (42)
	{
		read(term->fd, buff, 7);
		if (interpreter(term, buff))
			break ;
		ft_bzero(buff, 7);
	}
}
