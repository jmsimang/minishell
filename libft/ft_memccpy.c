/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 18:00:19 by jmsimang          #+#    #+#             */
/*   Updated: 2017/08/03 11:35:04 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *)dst;
	str2 = (char *)src;
	while (n--)
	{
		*str1 = *str2;
		str1++;
		if (*str2 == (char)c)
			return (str1);
		str2++;
	}
	return (NULL);
}
