/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:34:02 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/14 12:29:43 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_select.h"
#include "libft.h"

int		calculate_nbr_pages(t_term *term)
{
	int		nbperpage;

	nbperpage = (term->max.x * (term->wsize.ws_row - 8));
	return (((term->qty + nbperpage - 1) / nbperpage) - 1);
}

bool	check_window_size(t_term *term)
{
	print_cap("cl");
	if (ioctl(term->fd, TIOCGWINSZ, &term->wsize) == -1)
		return (false);
	if (term->wsize.ws_col < 58 || term->wsize.ws_row <= 17)
	{
		ft_putendl_fd("Please resize your terminal.", term->fd);
		return (false);
	}
	return (true);
}

bool	is_position_exist(t_term *term, int x, int y)
{
	t_choice	*current;

	current = term->choices;
	print_cap("cl");
	while (current)
	{
		if (current->pos.x == x && current->pos.y == y)
			return (true);
		current = current->next;
	}
	return (false);
}
