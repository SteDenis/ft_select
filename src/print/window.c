/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:15:28 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/14 12:29:03 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

static void	print_top(const char *content, t_term *term)
{
	box_top(1, 0, term->wsize.ws_col - term->start_y, term->fd);
	box_left_or_right(1, 1, term->fd);
	box_left_or_right(term->wsize.ws_col - 2, 1, term->fd);
	box_bottom(1, 2, term->wsize.ws_col - term->start_y, term->fd);
	goto_cap("cm", 3, 1);
	ft_putstr_fd(content, term->fd);
	goto_cap("cm", term->wsize.ws_col - 32, 1);
	print_cap("mr");
	ft_putstr_fd("  Selected : ", term->fd);
	ft_putnbr_fd(term->qty_s, term->fd);
	ft_putstr_fd("  Page : ", term->fd);
	ft_putnbr_fd(term->page, term->fd);
	ft_putstr_fd("/", term->fd);
	ft_putnbr_fd(term->max_p, term->fd);
	ft_putstr_fd("  ", term->fd);
	print_cap("me");
}

static void	print_bottom(t_term *term)
{
	goto_cap("cm", 0, term->wsize.ws_row - 2);
	ft_putstr_fd("\x1B[7m[SP]\x1B[0m   Select/Unselect  ", term->fd);
	ft_putstr_fd("\x1B[7m[RET]\x1B[0m  Valid Selection  ", term->fd);
	ft_putstr_fd("\x1B[7m[ESC]\x1B[0m  Quit    ", term->fd);
	ft_putstr_fd("\x1B[7m [o] \x1B[0m  Open directory", term->fd);
	goto_cap("cm", 0, term->wsize.ws_row - 1);
	ft_putstr_fd("\x1B[7m"ALTKEY" "LFTKEY, term->fd);
	ft_putstr_fd(" \x1B[0m   Previous Page    ", term->fd);
	ft_putstr_fd("\x1B[7m"ALTKEY"  "RGTKEY, term->fd);
	ft_putstr_fd(" \x1B[0m  Next Page        ", term->fd);
	ft_putstr_fd("\x1B[7m "CTLKEY" R \x1B[0m  Search  ", term->fd);
	ft_putstr_fd("\x1B[7m "BCKKEY" "DELKEY" \x1B[0m  Delete  ", term->fd);
}

static void	print_bottom_sm(t_term *term)
{
	goto_cap("cm", 0, term->wsize.ws_row - 2);
	ft_putstr_fd("\x1B[7m[SP]\x1B[0m (Un)Select ", term->fd);
	ft_putstr_fd("\x1B[7m[RET]\x1B[0m Finish ", term->fd);
	ft_putstr_fd("\x1B[7m[ESC]\x1B[0m Quit   ", term->fd);
	ft_putstr_fd("\x1B[7m [o] \x1B[0m Open dir.", term->fd);
	goto_cap("cm", 0, term->wsize.ws_row - 1);
	ft_putstr_fd("\x1B[7m"ALTKEY" "LFTKEY" \x1B[0m Prev.      ", term->fd);
	ft_putstr_fd("\x1B[7m"ALTKEY"  "RGTKEY" \x1B[0m Next   ", term->fd);
	ft_putstr_fd("\x1B[7m "CTLKEY" R \x1B[0m Search ", term->fd);
	ft_putstr_fd("\x1B[7m "BCKKEY" "DELKEY" \x1B[0m Del  ", term->fd);
}

int			print_top_bottom_bar(t_term *term)
{
	goto_cap("cm", 0, term->fd);
	print_top("ft_select by stdenis", term);
	if (term->wsize.ws_col >= 84)
		print_bottom(term);
	else
		print_bottom_sm(term);
	drawing_box(term);
	return (0);
}
