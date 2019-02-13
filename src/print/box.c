/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:07:46 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/13 11:37:03 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

void		drawing_box(t_term *term)
{
	size_t	i;
	size_t	y;

	y = term->start_y;
	box_top(1, 3, term->wsize.ws_col - y, term->fd);
	i = 3;
	while (i++ < term->wsize.ws_row - y)
		box_left_or_right(1, i, term->fd);
	i = 3;
	while (i++ < term->wsize.ws_row - y)
		box_left_or_right(term->wsize.ws_col - 2, i, term->fd);
	box_bottom(1, term->wsize.ws_row - y, term->wsize.ws_col - y, term->fd);
}

void		box_bottom(int x, int y, int length, int fd)
{
	int	i;

	i = 0;
	goto_cap("cm", x, y);
	ft_putstr_fd(BOXCGB, fd);
	while (i++ < length)
		ft_putstr_fd(BOXBT, fd);
	ft_putstr_fd(BOXCDB, fd);
}

void		box_top(int x, int y, int length, int fd)
{
	int	i;

	i = 0;
	goto_cap("cm", x, y);
	ft_putstr_fd(BOXCG, fd);
	while (i++ < length)
		ft_putstr_fd(BOXBT, fd);
	ft_putstr_fd(BOXCD, fd);
}

void		box_left_or_right(int x, int y, int fd)
{
	goto_cap("cm", x, y);
	ft_putstr_fd(BOXLR, fd);
}
