/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:15:31 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/01 12:15:31 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "libft.h"
#include "ft_select.h"

void		add_choice(t_choice **alst, t_choice *node)
{
	t_choice	*curr;

	if (*alst == NULL)
		*alst = node;
	else
	{
		curr = *alst;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = node;
		node = curr;
	}
}

t_choice	*arg_to_node(char **value, t_term *term)
{
	t_choice	*node;

	if ((node = (t_choice *)malloc(sizeof(t_choice))) != NULL)
	{
		node->name = *value;
		node->length = ft_strlen(node->name);
		if (term->max_l < node->length)
			term->max_l = node->length;
		term->qty++;
		node->pos.x = 0;
		node->pos.y = 0;
		node->printed = false;
		node->selected = false;
		node->next = NULL;
	}
	return (node);
}

int		fill_list_choices(char **ag, t_term *term)
{
	int		i;
	t_choice	*head;

	i = 0;
	while (ag[i] != NULL)
	{
		add_choice(&head, arg_to_node(&ag[i], term));
		i++;
	}
	term->choices = head;
	return (0);
}
