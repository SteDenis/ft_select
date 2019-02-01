/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:15:28 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/01 12:36:14 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

void		print_top(const char *content, t_term *term)
{
	size_t	len;

	ft_putstr(BGW);
	ft_putstr(BGEOL);
	ft_putstr(BGW);
	len = ft_strlen(content);
	len = (term->wsize.ws_col - len) / 2;
	goto_cap("cm", len, 0);
	ft_putstr(content);
	ft_putstr(BGEOL);
}

void		print_bottom(const char *content, t_term *term)
{
	size_t	len;

	ft_putstr(BGC);
	ft_putstr(BGEOL);
	ft_putstr(BGC);
	len = ft_strlen(content);
	len = (term->wsize.ws_col - len) / 2;
	goto_cap("cm", len, term->wsize.ws_row - 1);
	ft_putstr(content);
	ft_putstr(BGEOL);
}

int			print_top_bottom_bar(t_term *term)
{
	goto_cap("cm", 0, 0);
	print_top("ft_select by stdenis v0.1", term);
	goto_cap("cm", 0, term->wsize.ws_row - 1);
	print_bottom("Selected item : 0", term);
	return (0);
}
