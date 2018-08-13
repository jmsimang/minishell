/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 17:05:52 by jmsimang          #+#    #+#             */
/*   Updated: 2017/08/03 11:35:04 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int a;
	int b;
	int c;

	a = 0;
	b = -1;
	c = 0;
	while (little[a])
		a++;
	if (a == 0)
		return ((char *)big);
	while (big[++b])
	{
		while (little[c] == big[c + b])
		{
			if (c == a - 1)
				return ((char *)big + b);
			c++;
		}
		c = 0;
	}
	return (NULL);
}
