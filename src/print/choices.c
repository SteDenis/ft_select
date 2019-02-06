/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:15:14 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/06 13:12:41 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_select.h"

void	calculate_start_print(t_term *term)
{
	term->max.x = (term->wsize.ws_col - (CENTER * 2)) / term->max_l;
	term->max.y = 0;
	term->pos.x = CENTER;
	term->pos.y = 4;
}

void	print_type(int type)
{
	if (type == 1)
	{
		write(1, TXTR, 5);
		ft_putstr(EXE"  ");
	}
	else if (type == 2)
	{
		write(1, TXTB, 5);
		ft_putstr(FOLDER"  ");
	}
	else if (type >= 3)
	{
		write(1, TXTM, 5);
		ft_putstr(EFILE"  ");
	}
	else
		ft_putstr(NOTF"  ");
}

void	details_print(t_term *term, t_xy start, t_choice *choice)
{
	bool	on_cursor;

	on_cursor = (start.x == term->pos.x && start.y == term->pos.y);
	goto_cap("cm", start.x, start.y);
	if (on_cursor)
		print_cap("us");
	if (choice->selected)
		print_cap("mr");
	print_type(choice->type);
	if (on_cursor)
		ft_putstr(CURSOR" ");
	else
		ft_putstr("  ");
	ft_putendl_fd(choice->name, 2);
	write(1, TXTN, 5);
	if (choice->selected)
		print_cap("me");
	if (on_cursor)
		print_cap("ue");
	choice->pos.x = start.x;
	choice->pos.y = start.y;
}

void	print_printable_choices(t_term *term)
{
	t_choice	*current;
	t_xy		start;
	size_t 		i;

	current = term->choices;
	start.y = 4;
	term->max.y = 0;
	i = 0;
	start.x = CENTER;
	while (current)
	{
		if (current->printed)
		{
			details_print(term, start, current);
			start.x += term->max_l + 1;
			if ((i + 1) % term->max.x == 0)
			{
				start.y++;
				term->max.y++;
				start.x = CENTER;
			}
			i++;
		}
		current = current->next;
	}
	print_top_bottom_bar(term);
}

void	print_list_choices(t_term *term)
{
	t_choice	*current;
	t_xy		start;
	size_t 		i;

	current = term->choices;
	start.y = 4;
	term->max_p = calculate_nbr_pages(term);
	term->page = 0;
	i = 0;
	while (current)
	{
		if (current->search)
		{
			if (start.y >= term->wsize.ws_row - 4)
				current->printed = false;
			else
				current->printed = true;
			if ((i + 1) % term->max.x == 0)
				start.y++;
			i++;
		}
		current = current->next;
	}
	print_printable_choices(term);
}
