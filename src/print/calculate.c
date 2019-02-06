/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:34:02 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/06 12:04:33 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		calculate_nbr_pages(t_term *term)
{
	int		nbperpage;

	nbperpage = (term->max.x * (term->wsize.ws_row - 8));
	return (((term->qty + nbperpage - 1) / nbperpage) - 1);
}

