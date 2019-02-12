/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:15:36 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/08 09:55:55 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

void		return_select(t_term *term)
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

	(void)ac;
	if (init_term(&term))
		return (1);
	fill_list_choices(&ag[1], &term);
	ret = loop_select(&term);
	end_select(&term);
	if (ret == 1)
		return_select(&term);
	return (0);
}
