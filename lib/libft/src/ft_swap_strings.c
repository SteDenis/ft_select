/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:14:17 by stdenis           #+#    #+#             */
/*   Updated: 2018/11/15 16:14:40 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_strings(char **str, char **str2)
{
	char *swap;

	swap = *str;
	*str = *str2;
	*str2 = swap;
}
