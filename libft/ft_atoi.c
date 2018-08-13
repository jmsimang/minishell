/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 12:23:24 by jmsimang          #+#    #+#             */
/*   Updated: 2017/08/03 11:35:04 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\r' ||
				*str == '\f' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str != '\0' && ft_isdigit(*str))
	{
		res = (res * 10) + (*str++ - '0');
		i++;
	}
	if ((i > 19 || res > 9223372036854775807) && sign == 1)
		return (-1);
	if ((i > 19 || res > 9223372036854775807) && sign == -1)
		return (0);
	return ((int)res * sign);
}
