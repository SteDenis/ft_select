/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:40:38 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/13 12:23:15 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ft_select.h"
#include "libft.h"

static void	recover_qty_maxl(t_term *term)
{
	t_choice	*curr;

	curr = term->choices;
	term->qty = 0;
	term->max_l = 0;
	while (curr)
	{
		if (term->max_l < (int)curr->length + 6)
			term->max_l = (int)curr->length + 10;
		term->qty++;
		curr->search = true;
		curr->selected = false;
		curr = curr->next;
	}
	ft_strcpy(term->path, "");
}

void		recover_first_list(t_term *term)
{
	t_choice	*tmp;

	while (term->choices)
	{
		tmp = term->choices->next;
		if (term->choices->freeable)
			ft_strdel(&term->choices->name);
		free(term->choices);
		term->choices = tmp;
	}
	term->qty_s = 0;
	term->choices = term->first_list;
	term->first_list = NULL;
	recover_qty_maxl(term);
	print_cap("cl");
	calculate_start_print(term);
	print_list_choices(term);
}

int			denied_access(t_term *term)
{
	size_t	len;

	len = ft_strlen(term->path);
	while (term->path[len] != '/')
		len--;
	term->path[len] = '\0';
	goto_cap("cm", 0, term->wsize.ws_row - 3);
	ft_putstr_fd("\x1b[48;5;253;1;38;5;17mAccess Denied.\x1B[K", term->fd);
	ft_putstr_fd("\x1B[0m", term->fd);
	return (1);
}

void		change_list(t_choice *head, t_term *term)
{
	t_choice	*tmp;

	if (term->first_list == NULL)
		term->first_list = term->choices;
	else
	{
		while (term->choices)
		{
			tmp = term->choices->next;
			if (term->choices->freeable)
				ft_strdel(&term->choices->name);
			free(term->choices);
			term->choices = tmp;
		}
	}
	term->qty_s = 0;
	term->choices = head;
	print_cap("cl");
	calculate_start_print(term);
	print_list_choices(term);
}

void		add_node(t_choice **head, t_dir *dir, t_term *term)
{
	char		*name;
	t_choice	*node;

	if (dir->d_name[0] != '.')
	{
		if (!(name = ft_strdup(dir->d_name)))
			return ;
		node = arg_to_node(&name, term);
		if (node != NULL)
		{
			node->freeable = true;
			add_choice(head, node);
		}
	}
}
