/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 23:23:35 by jmsimang          #+#    #+#             */
/*   Updated: 2017/08/03 11:35:04 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *prev;
	t_list *first;

	first = NULL;
	prev = NULL;
	while (lst)
	{
		new = (*f)(lst);
		if (new == NULL)
			return (NULL);
		if (!first)
		{
			first = new;
			first->next = NULL;
		}
		else if (first && first->next == NULL)
			first->next = new;
		if (prev)
			prev->next = new;
		prev = new;
		lst = lst->next;
	}
	return (first);
}
