/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:22:37 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/13 12:32:44 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termcap.h>
#include "ft_select.h"
#include "libft.h"

void	free_term(t_term *term)
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
	term->choices = NULL;
	while (term->first_list)
	{
		tmp = term->first_list->next;
		if (term->first_list->freeable)
			ft_strdel(&term->first_list->name);
		free(term->first_list);
		term->first_list = tmp;
	}
	term->first_list = NULL;
}

void	end_select(t_term *term)
{
	if (term->search != NULL)
		ft_strdel(&term->search);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term->org_term);
	close(term->fd);
	print_cap("ve");
	print_cap("te");
}
