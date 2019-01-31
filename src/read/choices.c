//
// Created by Steve Denis on 2019-01-31.
//

#include <stdlib.h>
#include "ft_select.h"

int		fill_list_choices(char **ag, t_term *term)
{
	int		i;
	t_choice	*head;

	i = 0;
	while (ag[i] != NULL)
	{
		add_choice(ag[i], &head);
		i++;
	}
}