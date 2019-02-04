/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:15:28 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/04 17:37:33 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

void		print_top(const char *content, t_term *term)
{
	size_t	len;
	int 	i;


	len = ft_strlen(content);
	len = (term->wsize.ws_col - len) / 2;
	i = 0;
	goto_cap("cm", 1, 0);
	ft_putstr(BOXCG);
	while (i++ < term->wsize.ws_col - 4)
		ft_putstr(BOXBT);
	ft_putstr(BOXCD);
	goto_cap("cm", 1, 1);
	ft_putstr(BOXLR);
	goto_cap("cm",term->wsize.ws_col - 2, 1);
	ft_putstr(BOXLR);
	i = 0;
	goto_cap("cm", 1, 2);
	ft_putstr(BOXCGB);
	while (i++ < term->wsize.ws_col - 4)
		ft_putstr(BOXBT);
	ft_putstr(BOXCDB);
	goto_cap("cm", len, 1);
	ft_putstr(content);
}

void		print_bottom(const char *content, t_term *term)
{
	size_t	len;

	len = ft_strlen(content);
	len = (term->wsize.ws_col - len) / 2;
	goto_cap("cm", len, term->wsize.ws_row - 3);
	print_cap("mr");
	ft_putstr(content);
	ft_putnbr(term->qty_s);
	ft_putstr("  ");
	print_cap("me");
	goto_cap("cm", 0, term->wsize.ws_row - 2);
	ft_putstr("\x1B[7m[SPACE]\x1B[0m  Select/Unselect  ");
	ft_putstr("\x1B[7m[M-Left]\x1B[0m   Previous Page       ");
	ft_putstr("\x1B[7m[M-Right]\x1B[0m  Next Page        ");
	goto_cap("cm", 0, term->wsize.ws_row - 1);
	ft_putstr("\x1B[7m[ENTER]\x1B[0m  Valid Selection  ");
	ft_putstr("\x1B[7m[ESC]\x1B[0m      Quit without saving");
}

void		print_bottom_sm(const char *content, t_term *term)
{
	size_t	len;

	len = ft_strlen(content);
	len = (term->wsize.ws_col - len) / 2;
	goto_cap("cm", len, term->wsize.ws_row - 3);
	print_cap("mr");
	ft_putstr(content);
	ft_putnbr(term->qty_s);
	ft_putstr(" \x1B[0m");
}

void		drawing_box(t_term *term)
{
	size_t i;

	i = 0;
	goto_cap("cm", 1, 3);
	ft_putstr(BOXCG);
	while (i++ < term->wsize.ws_col - 4)
		ft_putstr(BOXBT);
	ft_putstr(BOXCD);
	i = 3;
	while (i++ < term->wsize.ws_row - 4)
	{
		goto_cap("cm", 1, i);
		ft_putstr(BOXLR);
	}
	i = 3;
	while (i++ < term->wsize.ws_row - 4)
	{
		goto_cap("cm", term->wsize.ws_col - 2, i);
		ft_putstr(BOXLR);
	}
	goto_cap("cm", 1, term->wsize.ws_row - 4);
	ft_putstr(BOXCGB);
	i = 0 ;
	while (i++ < term->wsize.ws_col - 4)
		ft_putstr(BOXBT);
	ft_putstr(BOXCDB);
}

int			print_top_bottom_bar(t_term *term)
{
	goto_cap("cm", 0, 0);
	print_top("ft_select by stdenis v0.1", term);
	goto_cap("cm", 0, term->wsize.ws_row - 1);
	if (term->wsize.ws_col >= 78)
		print_bottom("  Selected items on this page : ", term);
	else
		print_bottom_sm(" Selected : ", term);
	drawing_box(term);
	return (0);
}
