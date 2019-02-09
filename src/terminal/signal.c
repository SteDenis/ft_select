/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:39:33 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/08 12:12:45 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/ioctl.h>
#include "libft.h"
#include "ft_select.h"

static t_term	*g_term = NULL;

void	set_no_printed(t_term *term)
{
	t_choice	*choices;

	choices= term->choices;
	while (choices)
	{
		choices->printed = false;
		choices = choices->next;
	}
}

void	resize_handler(int signo)
{
	t_term *term;

	term = g_term;
	if (signo == SIGWINCH)
	{
		if (ioctl(0, TIOCGWINSZ, &term->wsize) != -1)
		{
			print_cap("cl");
			if (term->wsize.ws_col <= 60 || term->wsize.ws_row <= 25)
				ft_putendl_fd("Please resize your terminal.", 0);
			else
			{
				calculate_start_print(term);
				set_no_printed(term);
				print_list_choices(term);
			}

		}
	}
}
#include <unistd.h>
void		stop_handler(int signo)
{
	t_term *term;

	term = g_term;

	(void)signo;
	tcsetattr(term->fd, TCSAFLUSH, &term->org_term);
	signal(SIGTSTP, SIG_DFL);
	print_cap("te");
	print_cap("ve");
	ioctl(term->fd, TIOCSTI, "\x1A");
}

void		cont_handler(int signo)
{
	t_term *term;

	term = g_term;
	(void)signo;
	tcsetattr(term->fd, TCSAFLUSH, &term->n_term);
	print_cap("vi");
	print_cap("ti");
	signal(SIGTSTP, stop_handler);
	print_list_choices(term);
}

void		enable_signal(t_term *term)
{
	g_term = term;
	signal(SIGINT, SIG_IGN);
	signal(SIGWINCH, resize_handler);
	signal(SIGKILL, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTSTP, stop_handler);
	signal(SIGCONT, cont_handler);
}
