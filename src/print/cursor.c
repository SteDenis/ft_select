/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:08:00 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/06 13:20:55 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

void	move_right(t_term *term, int down)
{
	int		newpos;
	int		maxpos;

	newpos = term->pos.x + term->max_l + 1;
	maxpos = ((term->max_l + 1) * term->max.x) + CENTER;
	if (newpos < maxpos)
		term->pos.x += term->max_l + 1;
	else
	{
		term->pos.x = CENTER;
		if (down == 1)
			move_down(term, term->fd);
	}
}

void	move_left(t_term *term, int up)
{
	if (term->pos.x - (term->max_l + 1) >= CENTER)
		term->pos.x -= (term->max_l + 1);
	else
	{
		term->pos.x = (CENTER) + ((term->max_l + 1) * (term->max.x - 1));
		if (up == 1)
			move_up(term);
	}

}

void	move_up(t_term *term)
{
	if (term->pos.y - 1 >= 4)
		term->pos.y -= 1;
	else
	{
		term->pos.y = term->max.y + 4;
		if (term->pos.x - (term->max_l + 1) >= CENTER)
			move_left(term, term->fd);
	}
}

void	move_down(t_term *term, int right)
{
	if (term->pos.y + 1 <= term->max.y + 4)
		term->pos.y += 1;
	else
	{
		term->pos.y = 4;
		if (right == 1)
			move_right(term, term->fd);
	}
}

void	move_cursor(t_term *term, char buff[])
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
	print_printable_choices(term);
}

