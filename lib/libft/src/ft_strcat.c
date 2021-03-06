/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:48:05 by stdenis           #+#    #+#             */
/*   Updated: 2018/11/09 12:07:32 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	ls1;

	i = 0;
	ls1 = ft_strlen(s1);
	while (s2[i])
	{
		s1[ls1 + i] = s2[i];
		i++;
	}
	s1[ls1 + i] = '\0';
	return (s1);
}
