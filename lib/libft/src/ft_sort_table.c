/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:12:59 by stdenis           #+#    #+#             */
/*   Updated: 2018/11/15 16:20:29 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_table(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i] != 0)
	{
		j = 0;
		while (tab[j] != 0)
		{
			if (ft_strcmp((char*)tab[j], (char*)tab[i]) > 0)
			{
				ft_swap_strings(&tab[i], &tab[j]);
			}
			j++;
		}
		i++;
	}
}
