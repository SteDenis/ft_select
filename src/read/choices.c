/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:15:31 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/04 15:23:19 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <sys/stat.h>
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
		node->prev = curr;
	}
}

int			check_type(struct stat stats)
{
	if (stats.st_mode & S_IEXEC && !(S_ISDIR(stats.st_mode)))
		return (1);
	if (stats.st_mode & S_IEXEC && (S_ISDIR(stats.st_mode)))
		return (2);
	if ((S_ISLNK(stats.st_mode)))
		return (3);
	return (4);
}

t_choice	*arg_to_node(char **value, t_term *term)
{
	t_choice	*node;
	struct stat stats;

	if ((node = (t_choice *)malloc(sizeof(t_choice))) != NULL)
	{
		node->name = *value;
		node->length = ft_strlen(node->name);
		if (term->max_l < (int)node->length)
			term->max_l = node->length + 8;
		if (stat(*value, &stats) != -1)
			node->type = check_type(stats);
		else
			node->type = 0;
		term->qty++;
		node->pos.x = 0;
		node->pos.y = 0;
		node->printed = false;
		node->selected = false;
		node->next = NULL;
		node->prev = NULL;
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

