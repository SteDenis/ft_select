//
// Created by Steve Denis on 2019-01-31.
//

#include <unistd.h>
#include "ft_select.h"

void		loop_select(t_term *term)
{
	char buff[7];

	(void)term;
	while (42)
	{
		print_top_bottom_bar(term);
		read(STDIN_FILENO, buff, 7);
		if (buff[0] == 49)
			break;
	}
}
