/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:22:30 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/14 15:15:28 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"
#include "libft.h"

static void	free_elem(t_choice **node)
{
	t_choice	*n;

	n = *node;
	if (n->freeable)
		ft_strdel(&n->name);
	free(n);
	*node = NULL;
}

static void	re(t_term **term, t_choice **prev, t_choice **next, t_choice **curr)
{
	if ((*curr)->selected)
		(*term)->qty_s--;
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

int			del_elem(t_term **term)
{
	t_choice	*curr;
	t_choice	*prev;
	t_choice	*next;

	curr = (*term)->choices;
	prev = NULL;
	while (curr)
	{
		if (curr->pos.x == (*term)->pos.x && curr->pos.y == (*term)->pos.y)
		{
			if (!(ft_strequ("../", curr->name)))
				re(term, &prev, &next, &curr);
			break ;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
	if ((*term)->choices == NULL)
		return (1);
	if (check_window_size(*term))
		print_list_choices(*term);
	return (0);
}
