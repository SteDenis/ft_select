/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:15:36 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/13 12:26:32 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

static void	return_select(t_term *term)
{
	t_choice	*choices;
	bool		first;

	first = true;
	choices = term->choices;
	while (choices)
	{
		if (choices->selected)
		{
			if (!first)
				ft_putstr(" ");
			if (ft_strlen(term->path) > 0)
			{
				ft_putstr(term->path);
				ft_putchar('/');
			}
			ft_putstr(choices->name);
			first = false;
		}
		choices = choices->next;
	}
}

int			main(int ac, char **ag)
{
	t_term		term;
	int			ret;

	if (ac < 2)
		return (0);
	if (init_term(&term))
		return (1);
	fill_list_choices(&ag[1], &term);
	ret = loop_select(&term);
	end_select(&term);
	if (ret == 1)
		return_select(&term);
	free_term(&term);
	return (0);
}
