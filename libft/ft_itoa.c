/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 23:15:47 by jmsimang          #+#    #+#             */
/*   Updated: 2017/08/03 11:35:04 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static long long	ft_docheck(long long num)
{
	int len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	char		*str;
	long long	nbr;
	int			len;
	int			sign;

	sign = (n >= 0) ? 0 : 1;
	nbr = (long long)n;
	nbr = (sign == 1) ? -nbr : nbr;
	len = (sign == 1) ? ft_docheck(nbr) + 1 : ft_docheck(nbr);
	if ((str = ft_strnew(len)) == 0)
		return (0);
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (sign == 1)
		str[0] = '-';
	str[len + 1] = '\0';
	while (len-- > sign)
	{
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}
