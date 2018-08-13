/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 20:00:05 by jmsimang          #+#    #+#             */
/*   Updated: 2017/08/03 11:30:03 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_swap(void *a, void *b, size_t s)
{
	void *tmp;

	tmp = (void *)ft_memalloc(s);
	ft_memcpy(tmp, a, s);
	ft_memcpy(a, b, s);
	ft_memcpy(b, tmp, s);
	free(tmp);
}
