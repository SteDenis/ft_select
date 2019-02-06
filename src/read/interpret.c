/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:38:11 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/06 14:19:36 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

void	select_item(t_term *term)
{
	t_choice	*choices;

	choices = term->choices;
	while (choices)
	{
		if (choices->pos.x == term->pos.x && choices->pos.y == term->pos.y)
		{
			if (choices->selected)
				term->qty_s--;
			else
				term->qty_s++;
			choices->selected = !choices->selected;
			move_right(term, 1);
			break ;
		}
		choices = choices->next;
	}
	print_cap("cl");
	print_printable_choices(term);
}

void	change_printed(t_term *term, t_choice *current, int order)
{
	t_xy		start;
	size_t		i;

	start.y = 4;
	term->max.y = 0;
	i = 0;
	while (current)
	{
		if (start.y >= term->wsize.ws_row - 4)
			current->printed = false;
		else
			current->printed = true;
		if ((i + 1) % term->max.x == 0)
			start.y++;
		i++;
		if (order == 1)
			current = current->next;
		else
			current = current->prev;
	}
	print_cap("cl");
	print_printable_choices(term);
}

void	prev_page(t_term *term)
{
	t_choice	*current;
	t_choice	*save;

	save = NULL;
	current = term->choices;
	while (current)
	{
		if (save == NULL && current->next != NULL && current->next->printed)
			save = current;
		if (current->printed)
			reset_choice(current);
		current = current->next;
	}
	term->page--;
	change_printed(term, save, 0);
}

void	next_page(t_term *term)
{
	t_choice	*curr;

	curr = term->choices;
	while (curr)
	{
		if (curr->printed && curr->next != NULL && !curr->next->printed)
		{
			reset_choice(curr);
			curr = curr->next;
			break ;
		}
		else if (curr->printed)
			reset_choice(curr);
		curr = curr->next;
	}
	term->page++;
	change_printed(term, curr, 1);
}

void	switch_page(t_term *term, char buff[])
{
	if (LEFT(3) && term->page > 0)
		prev_page(term);
	else if (RIGHT(3) && term->max_p > 0 && term->page < term->max_p)
		next_page(term);
}
