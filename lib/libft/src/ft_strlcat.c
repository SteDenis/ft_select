/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:52:07 by stdenis           #+#    #+#             */
/*   Updated: 2018/11/09 10:44:05 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstl;
	size_t	srcl;
	size_t	i;

	i = 0;
	dstl = 0;
	srcl = ft_strlen((char*)src);
	while (dst[dstl] != '\0' && dstl < size)
		dstl++;
	while (i + dstl + 1 < size && src[i] != '\0')
	{
		dst[dstl + i] = src[i];
		i++;
	}
	if (size != 0 && size > dstl)
		dst[dstl + i] = '\0';
	return (srcl + dstl);
}
