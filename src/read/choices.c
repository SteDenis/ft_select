/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:15:31 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/13 14:50:54 by stdenis          ###   ########.fr       */
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

static int	check_type(struct stat stats)
{
	if (stats.st_mode & S_IEXEC && !(S_ISDIR(stats.st_mode)))
		return (1);
	if ((S_ISDIR(stats.st_mode)))
		return (2);
	if ((S_ISLNK(stats.st_mode)))
		return (3);
	return (4);
}

t_choice	*arg_to_node(char **value, t_term *term)
{
	t_choice	*node;
	char		path[1024];
	struct stat stats;

	ft_strcpy(path, term->path);
	ft_strcat_path(path, *value);
	if ((node = (t_choice *)malloc(sizeof(t_choice))) != NULL)
	{
		node->name = *value;
		node->length = ft_strlen(node->name);
		if (term->max_l < (int)node->length + 6)
			term->max_l = (int)node->length + 10;
		if (stat(path, &stats) != -1)
			node->type = check_type(stats);
		else
			node->type = 0;
		term->qty++;
		reset_choice(node);
		node->search = true;
		node->selected = false;
		node->freeable = false;
		node->next = NULL;
		node->prev = NULL;
	}
	return (node);
}

void		reset_choice(t_choice *choice)
{
	choice->printed = false;
	choice->pos.x = 0;
	choice->pos.y = 0;
}

int			fill_list_choices(char **ag, t_term *term)
{
	int			i;
	t_choice	*head;

	i = 0;
	head = NULL;
	ft_strcpy(term->path, "");
	while (ag[i] != NULL)
	{
		add_choice(&head, arg_to_node(&ag[i], term));
		i++;
	}
	term->choices = head;
	return (0);
}
