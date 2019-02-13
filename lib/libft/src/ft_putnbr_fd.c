/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:13:23 by stdenis           #+#    #+#             */
/*   Updated: 2018/11/13 18:14:36 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	res;

	res = n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	res = (n < 0) ? (res * -1) : n;
	if (res > 9)
	{
		ft_putnbr_fd(res / 10, fd);
		ft_putchar_fd((res % 10) + '0', fd);
	}
	else
		ft_putchar_fd(res + '0', fd);
}
