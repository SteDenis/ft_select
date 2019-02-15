/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:53:13 by stdenis           #+#    #+#             */
/*   Updated: 2018/11/15 11:08:19 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;

	current = *alst;
	while (*alst)
	{
		current = current->next;
		ft_lstdelone(alst, (*del));
		*alst = current;
	}
	*alst = NULL;
}
