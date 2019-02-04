/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:22:30 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/04 17:20:20 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"
#include "libft.h"
#include <unistd.h>

void		free_elem(t_choice **node)
{
	t_choice	*n;

	n = *node;
	free(n);
	*node = NULL;
}

int			del_elem(t_term **term)
{
	t_choice	*choices;
	t_choice	*prev;
	t_choice	*next;

	choices = (*term)->choices;
	prev = NULL;
	while (choices)
	{
		if (choices->pos.x == (*term)->pos.x && choices->pos.y  == (*term)->pos.y)
		{
			(*term)->qty--;
			next = choices->next;
			free_elem(&choices);
			if (prev != NULL)
			{
				prev->next = next;
				if (next != NULL)
					next->prev = prev;
				(*term)->pos.x = prev->pos.x;
				(*term)->pos.y = prev->pos.y;
			}
			else
			{
				(*term)->choices = next;
				if (next != NULL)
					(*term)->choices->prev = NULL;
			}
			break ;
		}
		else
		{
			prev = choices;
			choices = choices->next;
		}
	}
	print_cap("cl");
	if ((*term)->choices == NULL)
		return (1);
	print_list_choices(*term);
	return (0);
}
