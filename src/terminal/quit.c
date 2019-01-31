//
// Created by Steve Denis on 2019-01-31.
//

#include <unistd.h>
#include <termcap.h>
#include "ft_select.h"

void	end_select(t_term *term)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term->org_term);
	print_cap("ve");
	print_cap("te");
}
