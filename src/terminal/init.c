/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:22:17 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/08 10:46:09 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termcap.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_select.h"

static int	disable_echo_ecanon(t_term *term)
{
	if ((tcgetattr(0, &term->org_term)) == -1)
	{
		ft_putendl_fd("ft_select: can't get terminal attributes.", 2);
		return (1);
	}
	if ((tcgetattr(0, &term->n_term)) == -1)
	{
		ft_putendl_fd("ft_select: can't get terminal attributes.", 2);
		return (1);
	}
	term->n_term.c_lflag &= ~((unsigned long)ECHO | (unsigned long)ICANON);
	term->n_term.c_cc[VMIN] = 1;
	term->n_term.c_cc[VTIME] = 0;
	if ((tcsetattr(0, TCSAFLUSH, &term->n_term)) == -1)
	{
		ft_putendl_fd("ft_select: can't set terminal attributes.", 2);
		return (1);
	}
	print_cap("ti");
	print_cap("vi");
	return (0);
}

static int	init_struct(t_term *term)
{
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &term->wsize) == -1)
		return (1);
	term->pos.x = 0;
	term->pos.y = 0;
	term->max.x = 0;
	term->max.y = 0;
	term->max_l = 0;
	term->qty = 0;
	term->qty_s = 0;
	term->choices = NULL;
	term->search = NULL;
	return (0);
}

static int	init_fd_stdin(t_term *term)
{
	char	*tty_name;

	if (isatty(0))
	{
		tty_name = ttyname(0);
		term->fd = open(tty_name, O_RDWR);
	}
	return (0);
}

int			execute_tputs(int c)
{
	write(1, &c, 1);
	return (0);
}

int			init_term(t_term *term)
{
	char	*terminal;
	char	buff[1024];
	int		ret;

	if ((terminal = getenv("TERM")) == NULL)
	{
		ft_putstr_fd("ft_select: can't determine the terminal. ", 2);
		return (1);
	}
	if (ft_strequ(terminal, "dumb"))
	{
		ft_putstr_fd("ft_select: can't work on \"dumb\" terminal. ", 2);
		return (1);
	}
	if (tgetent(buff, terminal) != 1)
	{
		ft_putendl_fd("ft_select: terminal not found in tgetent.", 2);
		return (1);
	}
	if (init_struct(term))
		return (1);
	if (init_fd_stdin(term))
		return (1);
	ret = disable_echo_ecanon(term);
	return (ret);
}
