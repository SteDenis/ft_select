//
// Created by Steve Denis on 2019-01-31.
//

#include <unistd.h>
#include "libft.h"
#include "ft_select.h"

static int		interpreter(t_term *term, char buff[])
{
	if (ISARROW)
		move_cursor(term, buff);
	else if (RETURN)
		return (0);
	return (1);
}

void		loop_select(t_term *term)
{
	char buff[7];

	write(2, "\x1b[107m\x1b[2J", 12);
	goto_cap("cm", 0, 2);
	ft_putstr("\x1b[K\x1b[30m\x1b[1;4m Make your choices :\x1b[K\x1b[30m\x1b[1;4m ");
	print_top_bottom_bar(term);
	calculate_start_print(term);
	while (42)
	{
		print_list_choices(term);
		read(STDIN_FILENO, buff, 7);
		if (!(interpreter(term, buff)))
			break ;
		ft_bzero(buff, 7);
	}
}
