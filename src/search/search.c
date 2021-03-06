/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:34:00 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/14 12:34:24 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_select.h"

static void	print_search(t_term *term, size_t len)
{
	t_choice	*curr;

	curr = term->choices;
	term->qty = 0;
	while (curr)
	{
		if (ft_strnequ(curr->name, term->search, len) || len == 0)
		{
			term->qty++;
			curr->search = true;
		}
		else
			curr->search = false;
		reset_choice(curr);
		curr = curr->next;
	}
	print_cap("vi");
	print_cap("cl");
	calculate_start_print(term);
	if (check_window_size(term))
		print_list_choices(term);
}

static void	insert_char(t_term *term, char c)
{
	char	*tmp;
	char	buff[2];

	buff[0] = c;
	buff[1] = '\0';
	tmp = term->search;
	if ((term->search = ft_strjoin(term->search, buff)))
		free(tmp);
	else
		term->search = tmp;
}

static void	printable_char(t_term *term, char buff[])
{
	if (buff == NULL)
		return ;
	insert_char(term, buff[0]);
	print_search(term, ft_strlen(term->search));
	goto_cap("cm", 0, term->wsize.ws_row - 3);
	ft_putstr_fd("\x1b[48;5;253;1;38;5;17mSearch:\x1B[K", term->fd);
	ft_putstr_fd(term->search, term->fd);
	ft_putstr_fd("\x1B[0m", term->fd);
}

static void	suppr_char(t_term *term)
{
	char	*tmp;
	size_t	len;

	if ((len = ft_strlen(term->search)) == 0)
		return ;
	tmp = term->search;
	tmp[len - 1] = '\0';
	if ((term->search = ft_strdup(tmp)))
		free(tmp);
	else
		term->search = tmp;
	print_cap("cr");
	print_search(term, ft_strlen(term->search));
	goto_cap("cm", 0, term->wsize.ws_row - 3);
	ft_putstr_fd("\x1b[48;5;253;1;38;5;17mSearch:\x1B[K", term->fd);
	ft_putstr_fd(term->search, term->fd);
	ft_putstr_fd("\x1B[0m", term->fd);
}

void		search_items(t_term *term)
{
	char		buff[2];

	goto_cap("cm", 0, term->wsize.ws_row - 3);
	ft_putstr_fd("\x1b[48;5;253;1;38;5;17mSearch:\x1B[K", term->fd);
	ft_putstr_fd("\x1B[0m", term->fd);
	print_cap("ve");
	if (term->search == NULL)
	{
		if (!(term->search = ft_strnew(0)))
			return ;
	}
	else
		ft_putstr_fd(term->search, term->fd);
	while (read(0, buff, 2) > 0)
	{
		if (ISPRINT)
			printable_char(term, buff);
		else if (SUPPR)
			suppr_char(term);
		else
			break ;
	}
	goto_cap("cm", 0, term->wsize.ws_row - 3);
	print_cap("ce");
}
