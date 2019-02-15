/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:08:00 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/14 14:02:44 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

static void	move_left(t_term *term, int up)
{
	if (is_position_exist(term, term->pos.x - (term->max_l + 1), term->pos.y))
		term->pos.x -= (term->max_l + 1);
	else
	{
		term->pos.x = (CENTER) + ((term->max_l + 1) * (term->max.x - 1));
		if (up == 1 && term->pos.y > term->start_y)
			move_up(term);
	}
}

static void	move_down(t_term *term, int right)
{
	if (is_position_exist(term, term->pos.x, term->pos.y + 1))
		term->pos.y += 1;
	else
	{
		term->pos.y = term->start_y;
		if (right == 1)
			move_right(term, term->fd);
	}
}

void		move_up(t_term *term)
{
	if (is_position_exist(term, term->pos.x, term->pos.y - 1))
		term->pos.y -= 1;
	else
	{
		term->pos.y = term->start_y;
		if (term->pos.x - (term->max_l + 1) >= CENTER)
			move_left(term, term->fd);
	}
}

void		move_right(t_term *term, int down)
{
	int		newpos;

	newpos = term->pos.x + term->max_l + 1;
	if (is_position_exist(term, newpos, term->pos.y))
		term->pos.x += term->max_l + 1;
	else
	{
		term->pos.x = CENTER;
		if (down == 1)
			move_down(term, term->fd);
	}
}

void		move_cursor(t_term *term, char buff[])
{
	if (LEFT(2))
		move_left(term, 1);
	else if (RIGHT(2))
		move_right(term, 1);
	else if (UP(2))
		move_up(term);
	else if (DOWN(2))
		move_down(term, 1);
	else if (IS_OPT_ARR)
		switch_page(term, buff);
	if (check_window_size(term))
	{
		print_printable_choices(term);
		print_top_bottom_bar(term);
	}
}
