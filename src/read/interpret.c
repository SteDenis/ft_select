/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:38:11 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/04 16:41:54 by stdenis          ###   ########.fr       */
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
		if (choices->pos.x == term->pos.x && choices->pos.y  == term->pos.y)
		{
			choices->selected = !choices->selected;
			move_right(term, 1);
			break ;
		}
		choices = choices->next;
	}
	print_cap("cl");
	print_printable_choices(term);
}

void reset_choice(t_choice *choice)
{
	choice->printed = false;
	choice->pos.x = 0;
	choice->pos.y = 0;
}

void	prev_page(t_term *term)
{
	t_choice	*current;
	t_choice	*save;
	t_xy		start;
	size_t 		i;

	save = NULL;
	current = term->choices;
	while (current)
	{
		if (save == NULL && current->next != NULL && current->next->printed)
			save = current->next;
		current->printed = false;
		current = current->next;
	}
	start.y = 4;
	term->max.y = 0;
	i = 0;
	while (save)
	{
		if (start.y >= term->wsize.ws_row - 4)
			save->printed = false;
		else
			save->printed = true;
		if ((i + 1) % term->max.x == 0)
			start.y++;
		i++;
		save = save->prev;
	}
	term->page--;
	print_cap("cl");
	print_printable_choices(term);

}

void	next_page(t_term *term)
{
	t_choice	*current;
	t_xy		start;
	size_t 		i;

	current = term->choices;
	while (current)
	{
		if (current->printed && current->next != NULL && !current->next->printed)
		{
			reset_choice(current);
			break ;
		}
		else if (current->printed)
			reset_choice(current);
		current = current->next;
	}
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
		current = current->next;
	}
	term->page++;
	print_cap("cl");
	print_printable_choices(term);

}

void	switch_page(t_term *term, char buff[])
{
	if (LEFT(3) && term->page > 0)
		prev_page(term);
	else if (RIGHT(3) && term->max_p > 0 && term->page <= term->max_p)
		next_page(term);
}
