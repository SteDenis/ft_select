/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:15:28 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/08 10:43:01 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

void		print_top(const char *content, t_term *term)
{
	box_top(1, 0, term->wsize.ws_col - 4);
	box_left_or_right(1, 1);
	box_left_or_right(term->wsize.ws_col - 2, 1);
	box_bottom(1, 2, term->wsize.ws_col - 4);
	goto_cap("cm", 3, 1);
	ft_putstr_fd(content, 0);
	goto_cap("cm", term->wsize.ws_col - 32, 1);
	print_cap("mr");
	ft_putstr_fd("  Selected : ", 0);
	ft_putnbr_fd(term->qty_s, 0);
	ft_putstr_fd("  Page : ", 0);
	ft_putnbr_fd(term->page, 0);
	ft_putstr_fd("/", 0);
	ft_putnbr_fd(term->max_p, 0);
	ft_putstr_fd("  ", 0);
	print_cap("me");
}

void		print_bottom(t_term *term)
{
	goto_cap("cm", 0, term->wsize.ws_row - 2);
	ft_putstr_fd("\x1B[7m[SPACE]\x1B[0m   Select/Unselect  ", 0);
	ft_putstr_fd("\x1B[7m[M-Left]\x1B[0m   Previous Page       ", 0);
	ft_putstr_fd("\x1B[7m[M-Right]\x1B[0m  Next Page        ", 0);
	goto_cap("cm", 0, term->wsize.ws_row - 1);
	ft_putstr_fd("\x1B[7m[RETURN]\x1B[0m  Valid Selection  ", 0);
	ft_putstr_fd("\x1B[7m[ESC]\x1B[0m      Quit without saving", 0);
}

void		print_bottom_sm(t_term *term)
{
	goto_cap("cm", 0, term->wsize.ws_row - 2);
	ft_putstr_fd("\x1B[7m[SPA]\x1B[0m  Select/Unselect ", 0);
	ft_putstr_fd("\x1B[7m[M-L]\x1B[0m  Prev.  ", 0);
	ft_putstr_fd("\x1B[7m[M-R]\x1B[0m  Next", 0);
	goto_cap("cm", 0, term->wsize.ws_row - 1);
	ft_putstr_fd("\x1B[7m[RET]\x1B[0m  Valid           ", 0);
	ft_putstr_fd("\x1B[7m[ESC]\x1B[0m  Quit ", 0);
}

int			print_top_bottom_bar(t_term *term)
{
	goto_cap("cm", 0, 0);
	print_top("ft_select by stdenis", term);
	if (term->wsize.ws_col >= 78)
		print_bottom(term);
	else
		print_bottom_sm(term);
	drawing_box(term);
	return (0);
}
