/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:22:37 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/08 09:53:10 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <termcap.h>
#include "ft_select.h"
#include "libft.h"

void	end_select(t_term *term)
{
	if (term->search != NULL)
		ft_strdel(&term->search);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term->org_term);
	print_cap("ve");
	print_cap("te");
}
