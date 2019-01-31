//
// Created by Steve Denis on 2019-01-31.
//
#include <unistd.h>
#include <termcap.h>
#include "libft.h"
#include "ft_select.h"

static int	disable_echo_ecanon(t_term *term)
{
	if ((tcgetattr(STDIN_FILENO, &term->org_term)) == -1)
	{
		ft_putendl_fd("ft_select: can't get terminal attributes.", 2);
		return (1);
	}
	if ((tcgetattr(STDIN_FILENO, &term->n_term)) == -1)
	{
		ft_putendl_fd("ft_select: can't get terminal attributes.", 2);
		return (1);
	}
	term->n_term.c_lflag &= ~((unsigned long)ECHO | (unsigned long)ICANON);
	term->n_term.c_cc[VMIN] = 1;
	term->n_term.c_cc[VTIME] = 0;
	if ((tcsetattr(STDIN_FILENO, TCSAFLUSH, &term->n_term)) == -1)
	{
		ft_putendl_fd("ft_select: can't set terminal attributes.", 2);
		return (1);
	}
	print_cap("ti");
	print_cap("vi");
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
	ret = disable_echo_ecanon(term);
	return (ret);
}
