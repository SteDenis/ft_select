//
// Created by Steve Denis on 2019-01-31.
//

#include "ft_select.h"

int		main(int ac, char **ag)
{
	t_term		term;

	(void)ac;
	(void)ag;
	if (init_term(&term))
		return (1);
	fill_list_choices(&ag[1], &term);
	loop_select(&term);
	end_select(&term);
	return (0);
}
