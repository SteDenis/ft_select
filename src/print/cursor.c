/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:08:00 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/01 16:03:09 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

void	move_right(t_term *term)
{
	if (term->pos.x + term->max_l + 1 < term->wsize.ws_col - (term->wsize.ws_col - (term->max_l * term->max.x)) / 2)
		term->pos.x += term->max_l + 1;
	else
		term->pos.x = (term->wsize.ws_col - (term->max_l * term->max.x)) / 2;
}

void	move_left(t_term *term)
{
	if (term->pos.x > (term->max_l + 1))
		term->pos.x -= (term->max_l + 1);
	else
		term->pos.x += (term->max_l + 1) * term->max.x;
	}

void	move_up(t_term *term)
{
	if (term->pos.y - 1 >= 4)
		term->pos.y -= 1;
	else
	{
		if (term->pos.x > (term->max_l + 1))
		{
			term->pos.y = term->max.y + 4;
			move_left(term);
		}
	}
}

void	move_down(t_term *term)
{
	if (term->pos.y + 1 <= term->max.y + 4)
		term->pos.y += 1;
	else
	{
		term->pos.y = 4;
		move_right(term);
	}
}

void	move_cursor(t_term *term, char buff[])
{
	print_cap("mr");
	print_top_bottom_bar(term);
	if (LEFT(2))
		move_left(term);
	else if (RIGHT(2))
		move_right(term);
	else if (UP(2))
		move_up(term);
	else if (DOWN(2))
		move_down(term);
}

