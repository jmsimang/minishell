/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 13:23:33 by jmsimang          #+#    #+#             */
/*   Updated: 2017/08/03 11:35:04 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t a;
	size_t b;
	size_t c;

	if (*little == '\0')
		return ((char *)big);
	a = ft_strlen(little);
	b = 0;
	while (big[b])
	{
		c = 0;
		while ((little[c] == big[c + b]) && ((c + b) < len))
		{
			if (c == a - 1)
				return ((char *)(big + b));
			c++;
		}
		b++;
	}
	return (NULL);
}
