/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:15:14 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/13 12:56:41 by stdenis          ###   ########.fr       */
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
	term->pos.y = term->start_y;
}

void	print_type(int type, t_term *term)
{
	if (type == 1)
	{
		ft_putstr_fd(TXTR, term->fd);
		ft_putstr_fd(EXE"  ", term->fd);
	}
	else if (type == 2)
	{
		ft_putstr_fd(TXTB, term->fd);
		ft_putstr_fd(FOLDER"  ", term->fd);
	}
	else if (type >= 3)
	{
		ft_putstr_fd(TXTM, term->fd);
		ft_putstr_fd(EFILE"  ", term->fd);
	}
	else
		ft_putstr_fd(NOTF"  ", term->fd);
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
	print_type(choice->type, term);
	if (on_cursor)
		ft_putstr_fd(CURSOR" ", term->fd);
	else
		ft_putstr_fd("  ", term->fd);
	ft_putendl_fd(choice->name, term->fd);
	ft_putstr_fd(TXTN, term->fd);
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
	size_t		i;

	current = term->choices;
	start.y = term->start_y;
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
}

void	print_list_choices(t_term *term)
{
	t_choice	*current;
	t_xy		start;
	size_t		i;

	current = term->choices;
	start.y = term->start_y;
	term->max_p = calculate_nbr_pages(term);
	term->page = 0;
	i = 0;
	while (current)
	{
		if (current->search)
		{
			if (start.y >= term->wsize.ws_row - term->start_y)
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
	print_top_bottom_bar(term);
}
