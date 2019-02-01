/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:15:36 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/01 12:15:36 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_select.h"

int		main(int ac, char **ag)
{
	t_term		term;

	(void)ac;
	if (init_term(&term))
		return (1);
	fill_list_choices(&ag[1], &term);
	loop_select(&term);
	end_select(&term);
	return (0);
}
