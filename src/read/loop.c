/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:34:06 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/12 11:15:41 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_select.h"

static int		interpreter(t_term *term, char buff[])
{
	if (ESCAPE)
		return (2);
	if (DEL && del_elem(&term))
		return (2);
	else if (ISARROW)
		move_cursor(term, buff);
	else if (SUPPR && del_elem(&term))
		return (2);
	else if (CTRLR)
		search_items(term);
	else if (SPACE)
		select_item(term);
	else if (RETURN)
		return (1);
	else if (OPEN)
		open_directory(term);
	return (0);
}

int				loop_select(t_term *term)
{
	char	buff[7];
	int		ret;

	if (check_window_size(term))
	{
		calculate_start_print(term);
		print_list_choices(term);
	}
	ret = 0;
	ft_bzero(buff, 7);
	while (read(term->fd, buff, 7) > 0)
	{
		if ((ret = interpreter(term, buff)) > 0)
			break ;
		ft_bzero(buff, 7);
	}
	return (ret);
}
