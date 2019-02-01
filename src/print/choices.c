/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:15:14 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/01 17:46:43 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_select.h"

void	calculate_start_print(t_term *term)
{
	term->max.x = term->wsize.ws_col / term->max_l;
	term->max.y = 0;
	term->pos.x = (term->wsize.ws_col - (term->max_l * term->max.x)) / 2;
	term->pos.y = 4;
}

void	print_list_choices(t_term *term)
{
	t_choice	*current;
	t_xy		start;
	size_t 		i;

	current = term->choices;
	start.y = 4;
	term->max.y = 0;
	i = 0;
	start.x = (term->wsize.ws_col - (term->max_l * term->max.x)) / 2;
	while (current)
	{
		goto_cap("cm", start.x, start.y);
		if (start.x == term->pos.x && start.y == term->pos.y)
			print_cap("mr");
		ft_putstr(REV);
		ft_putendl_fd(current->name, 2);
		if (start.x == term->pos.x && start.y == term->pos.y)
			print_cap("me");
		start.x += term->max_l + 1;
		if ((i + 1) % term->max.x == 0)
		{
			start.y++;
			term->max.y++;
			start.x = (term->wsize.ws_col - (term->max_l * term->max.x)) / 2;
		}
		i++;
		current = current->next;
	}
}
