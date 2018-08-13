/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:17:33 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/28 13:17:33 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa_base(int value, int base)
{
	int				size;
	char			*str;
	char			hex_v[16];
	unsigned int	i;

	ft_strcpy(hex_v, "0123456789ABCDEF");
	value = (value < 0 && base != 10) ? -value : value;
	i = (value < 0 && base == 10) ? -value : value;
	size = 1 + (value < 0 && base == 10);
	while ((i /= base))
		size++;
	str = (char *)ft_memalloc(sizeof(char) * size + 1);
	str[size] = '\0';
	i = (value < 0 && base == 10) ? -value : value;
	str[--size] = hex_v[i % base];
	while ((i /= base))
		str[--size] = hex_v[i % base];
	if (value < 0 && base == 10)
		str[--size] = '-';
	return (str);
}
