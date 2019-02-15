/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:39:33 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/14 14:18:58 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/ioctl.h>
#include "libft.h"
#include "ft_select.h"

static t_term	*g_term = NULL;

static void	resize_handler(int signo)
{
	t_term *term;

	term = g_term;
	if (signo == SIGWINCH)
	{
		if (ioctl(term->fd, TIOCGWINSZ, &term->wsize) != -1)
		{
			print_cap("cl");
			if (term->wsize.ws_col < 58 || term->wsize.ws_row <= 17)
				ft_putendl_fd("Please resize your terminal.", term->fd);
			else
			{
				calculate_start_print(term);
				print_list_choices(term);
			}
		}
	}
}

static void	stop_handler(int signo)
{
	t_term *term;

	term = g_term;
	if (signo == SIGTSTP)
	{
		tcsetattr(term->fd, TCSAFLUSH, &term->org_term);
		signal(SIGTSTP, SIG_DFL);
		print_cap("te");
		print_cap("ve");
		ioctl(term->fd, TIOCSTI, "\x1A");
	}
}

static void	cont_handler(int signo)
{
	t_term *term;

	term = g_term;
	if (signo == SIGCONT)
	{
		tcsetattr(term->fd, TCSAFLUSH, &term->n_term);
		print_cap("vi");
		print_cap("ti");
		signal(SIGTSTP, stop_handler);
		if (check_window_size(term))
			print_list_choices(term);
	}
}

static void	quit_handler(int signo)
{
	t_term *term;

	term = g_term;
	(void)signo;
	end_select(term);
	free_term(term);
	exit(1);
}

void		enable_signal(t_term *term)
{
	g_term = term;
	signal(SIGINT, quit_handler);
	signal(SIGWINCH, resize_handler);
	signal(SIGHUP, quit_handler);
	signal(SIGILL, quit_handler);
	signal(SIGTRAP, quit_handler);
	signal(SIGBUS, quit_handler);
	signal(SIGABRT, quit_handler);
	signal(SIGFPE, quit_handler);
	signal(SIGUSR1, SIG_IGN);
	signal(SIGUSR2, SIG_IGN);
	signal(SIGPIPE, SIG_IGN);
	signal(SIGALRM, SIG_IGN);
	signal(SIGSEGV, quit_handler);
	signal(SIGKILL, quit_handler);
	signal(SIGTERM, quit_handler);
	signal(SIGQUIT, quit_handler);
	signal(SIGTSTP, stop_handler);
	signal(SIGCONT, cont_handler);
}
