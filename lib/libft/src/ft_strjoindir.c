/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <stdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 13:28:06 by stdenis           #+#    #+#             */
/*   Updated: 2019/02/12 14:19:49 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoindir(char **s1, char *s2, int free)
{
	char	*tmp;
	char	*res;
	char	buff[2];
	int		i;

	tmp = *s1;
	i = 0;
	buff[0] = '/';
	buff[1] = '\0';
	while (s2[i] >= 32 && s2[i] <= 126)
		i++;
	s2[i] = '\0';
	res = (char*)malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	res = ft_strcpy(res, *s1);
	res = ft_strcat(res, buff);
	res = ft_strcat(res, s2);
	if (free == 1)
		ft_strdel(&tmp);
	return (res);
}
