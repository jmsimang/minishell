/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunequ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 12:20:18 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/28 13:23:21 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_strunequ(char const *s1, char const *s2)
{
	int res;

	res = -1;
	while (s2[++res])
		if (s1[res] != s2[res])
			return (0);
	return (1);
}
