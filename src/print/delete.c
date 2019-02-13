/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:22:30 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/13 14:28:16 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"
#include "libft.h"
#include <unistd.h>

void	free_elem(t_choice **node)
{
	t_choice	*n;

	n = *node;
	free(n);
	*node = NULL;
}

void	order(t_term **term, t_choice **prev, t_choice **next, t_choice **curr)
{
	(*term)->qty--;
	*next = (*curr)->next;
	free_elem(curr);
	if (*prev != NULL)
	{
		(*prev)->next = *next;
		if (*next != NULL)
			(*next)->prev = (*prev);
		(*term)->pos.x = (*prev)->pos.x;
		(*term)->pos.y = (*prev)->pos.y;
	}
	else
	{
		(*term)->choices = *next;
		if (*next != NULL)
			(*term)->choices->prev = NULL;
	}
}

int		del_elem(t_term **term)
{
	t_choice	*curr;
	t_choice	*prev;
	t_choice	*next;

	curr = (*term)->choices;
	prev = NULL;
	next = NULL;
	while (curr)
	{
		if (curr->pos.x == (*term)->pos.x && curr->pos.y == (*term)->pos.y)
		{
			order(term, &prev, &next, &curr);
			break ;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
	print_cap("cl");
	if ((*term)->choices == NULL)
		return (1);
	print_list_choices(*term);
	return (0);
}
