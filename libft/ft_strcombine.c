/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcombine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:31:03 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/19 16:34:52 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strcombine(char *s1, char *c, char *s2)
{
	char *temp;

	temp = ft_strjoin(s1, c);
	temp = ft_strjoin(temp, s2);
	return (temp);
}
