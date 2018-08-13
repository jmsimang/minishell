/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:29:08 by jmsimang          #+#    #+#             */
/*   Updated: 2017/08/03 11:35:04 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d_dst;
	unsigned char	*s_src;

	d_dst = (unsigned char *)dst;
	s_src = (unsigned char *)src;
	if (len == 0)
		return (dst);
	if (s_src < d_dst)
	{
		while (len)
		{
			d_dst[len - 1] = s_src[len - 1];
			len--;
		}
		return (dst);
	}
	else
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
}
