/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdenis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:43:44 by stdenis           #+#    #+#             */
/*   Updated: 2018/11/16 12:21:25 by stdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free_new(t_list **new)
{
	t_list *cur;

	while (new != NULL)
	{
		cur = (*new)->next;
		free(*new);
		*new = cur;
	}
	*new = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*current;
	t_list	*head;

	if (lst == NULL)
		return (NULL);
	current = lst;
	if (!(new = ft_lstnew(((*f)(current))->content,
						((*f)(current))->content_size)))
		return (NULL);
	head = new;
	while (current->next != NULL)
	{
		current = current->next;
		if (!(new->next = ft_lstnew(((*f)(current))->content,
									((*f)(current))->content_size)))
		{
			ft_free_new(&head);
			return (NULL);
		}
		new = new->next;
	}
	return (head);
}
