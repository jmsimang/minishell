/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:03:54 by jmsimang          #+#    #+#             */
/*   Updated: 2017/08/03 11:35:04 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t d_len;
	size_t s_len;
	size_t i;

	d_len = (size_t)ft_strlen(dst);
	s_len = (size_t)ft_strlen(src);
	i = d_len;
	while ((*src) && ((d_len + 1) < size))
		dst[d_len++] = *src++;
	dst[d_len] = '\0';
	if (i > size)
		return (s_len + size);
	else
		return (s_len + i);
}
