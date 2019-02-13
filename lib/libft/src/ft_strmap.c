/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:34:06 by stdenis           #+#    #+#             */
/*   Updated: 2018/11/13 18:20:16 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			fresh[i] = (*f)(s[i]);
			i++;
		}
		fresh[i] = '\0';
	}
	return (fresh);
}
