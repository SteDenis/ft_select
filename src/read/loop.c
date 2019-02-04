//
// Created by Steve Denis on 2019-01-31.
//

#include <unistd.h>
#include "libft.h"
#include "ft_select.h"

static int		interpreter(t_term *term, char buff[])
{
	if (DEL)
	{
		if (del_elem(&term))
			return (1);
	}
	else if (ISARROW)
		move_cursor(term, buff);
	else if (SUPPR)
	{
		if (del_elem(&term))
			return (1);
	}
	else if (SPACE)
		select_item(term);
	else if (RETURN)
		return (1);
	return (0);
}

void		loop_select(t_term *term)
{
	char buff[7];

	calculate_start_print(term);
	print_top_bottom_bar(term);
	print_list_choices(term);
	print_printable_choices(term);
	while (42)
	{
		read(STDIN_FILENO, buff, 7);
		if (interpreter(term, buff))
			break ;
		enable_signal(term);
		ft_bzero(buff, 7);
	}
}
