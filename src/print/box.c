/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:07:46 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/06 11:56:09 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

void		drawing_box(t_term *term)
{
	size_t i;

	box_top(1, 3, term->wsize.ws_col - 4);
	i = 3;
	while (i++ < term->wsize.ws_row - 4)
		box_left_or_right(1, i);
	i = 3;
	while (i++ < term->wsize.ws_row - 4)
		box_left_or_right(term->wsize.ws_col - 2, i);
	box_bottom(1, term->wsize.ws_row - 4, term->wsize.ws_col - 4);
}

void	box_bottom(int x, int y, int length)
{
	int 	i;

	i = 0;
	goto_cap("cm", x, y);
	ft_putstr(BOXCGB);
	while (i++ < length)
		ft_putstr(BOXBT);
	ft_putstr(BOXCDB);
}

void	box_top(int x, int y, int length)
{
	int 	i;

	i = 0;
	goto_cap("cm", x, y);
	ft_putstr(BOXCG);
	while (i++ < length)
		ft_putstr(BOXBT);
	ft_putstr(BOXCD);
}

void	box_left_or_right(int x, int y)
{
	goto_cap("cm", x, y);
	ft_putstr(BOXLR);
}
