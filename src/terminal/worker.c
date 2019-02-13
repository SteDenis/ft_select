/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:22:49 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/06 14:22:49 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termcap.h>
#include "libft.h"
#include "ft_select.h"

static char			*safe_tgetstr(const char *id, char **area)
{
	char	*rtn;
	char	*tmp;

	tmp = ft_strdup(id);
	if (tmp == NULL)
		return (NULL);
	rtn = tgetstr(tmp, area);
	ft_strdel(&tmp);
	return (rtn);
}

static int			safe_tputs(const char *str, int affcnt, int (*putc)(int))
{
	if (str != NULL)
	{
		return (tputs(str, affcnt, putc));
	}
	return (-1);
}

static const char	*safe_tgoto(const char *str, int x, int y)
{
	if (str != NULL)
	{
		return (tgoto(str, x, y));
	}
	return (NULL);
}

void				goto_cap(const char *id, int x, int y)
{
	safe_tputs(safe_tgoto(safe_tgetstr(id, NULL), x, y), 1, execute_tputs);
}

void				print_cap(const char *id)
{
	safe_tputs(safe_tgetstr(id, NULL), 1, execute_tputs);
}
