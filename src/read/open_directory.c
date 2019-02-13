/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:31:08 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/13 12:23:15 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "ft_select.h"
#include "libft.h"

static void		add_node_back(t_term *term, t_choice **head)
{
	t_choice	*node;
	char		*name;

	if (!(ft_strequ(term->path, ".")))
	{
		if (!(name = ft_strdup("../")))
			return ;
		if ((node = arg_to_node(&name, term)) != NULL)
		{
			node->freeable = true;
			add_choice(head, node);
		}
	}
}

static int		try_open_it(char *path, t_term *term, bool ret)
{
	DIR			*fd;
	t_choice	*head;
	t_dir		*dir;

	head = NULL;
	if (!ret)
		ft_strcat_path(term->path, path);
	fd = opendir(term->path);
	if (fd == NULL)
		return (denied_access(term));
	term->max_l = 0;
	term->qty = 0;
	add_node_back(term, &head);
	while ((dir = readdir(fd)) != NULL)
		add_node(&head, dir, term);
	closedir(fd);
	change_list(head, term);
	return (0);
}

static void		back_dir(t_term *term)
{
	size_t	len;

	len = ft_strlen(term->path);
	while (term->path[len] != '/' && len > 0)
		len--;
	term->path[len] = '\0';
	if (ft_strlen(term->path) == 0)
		recover_first_list(term);
	else
		try_open_it("/", term, true);
}

void			open_directory(t_term *term)
{
	t_choice	*choices;

	choices = term->choices;
	while (choices)
	{
		if (choices->pos.x == term->pos.x && choices->pos.y == term->pos.y)
		{
			if (choices->type == 2)
			{
				if (ft_strequ("../", choices->name))
					back_dir(term);
				else
					try_open_it(choices->name, term, false);
			}
			break ;
		}
		choices = choices->next;
	}
}
