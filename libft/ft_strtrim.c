/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 20:26:00 by jmsimang          #+#    #+#             */
/*   Updated: 2017/08/03 11:30:08 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	str = ft_strnew(ft_strlen(s));
	if (str == NULL)
		return (NULL);
	while (j < ft_strlen(s))
	{
		if (!i && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
			j++;
		else
			str[i++] = s[j++];
	}
	while (str[--i] == ' ' || str[i] == '\t' || str[i] == '\n')
		str[i] = '\0';
	return (str);
}
