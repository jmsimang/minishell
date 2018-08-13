/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 13:32:14 by jmsimang          #+#    #+#             */
/*   Updated: 2017/08/03 11:39:40 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *st, size_t n)
{
	unsigned char *str;

	str = (unsigned char *)st;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}
