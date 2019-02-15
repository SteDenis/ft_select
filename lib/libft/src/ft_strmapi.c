/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:37:38 by stdenis           #+#    #+#             */
/*   Updated: 2018/11/13 18:22:07 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fresh;

	i = 0;
	fresh = NULL;
	if (s != NULL)
	{
		if (!(fresh = ft_strdup((char*)s)))
			return (NULL);
		while (s[i] != '\0')
		{
			fresh[i] = (*f)(i, s[i]);
			i++;
		}
		fresh[i] = '\0';
	}
	return (fresh);
}
