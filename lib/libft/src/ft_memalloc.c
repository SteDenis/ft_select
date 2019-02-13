/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:23:09 by stdenis           #+#    #+#             */
/*   Updated: 2018/11/15 15:06:19 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*fresh;

	if (size == 0)
		return (NULL);
	if (!(fresh = (void*)malloc(size)))
		return (NULL);
	ft_memset(fresh, 0, size);
	return (fresh);
}
