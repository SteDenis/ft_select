/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 13:32:35 by stdenis           #+#    #+#             */
/*   Updated: 2018/11/13 18:22:57 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_spaces(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	return (i);
}

static int	ft_count_reverse_spaces(char const *s, size_t len)
{
	int	i;

	i = 0;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
	{
		len--;
		i++;
	}
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int			sp1;
	int			sp2;
	int			length;
	char		*new;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	sp1 = ft_count_spaces(s);
	if (sp1 < length)
		sp2 = ft_count_reverse_spaces(s, length - 1);
	else
		sp2 = -1;
	if (!(new = ft_strsub(s, sp1, length - sp1 - sp2)))
		return (NULL);
	return (new);
}
