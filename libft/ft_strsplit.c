/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 19:32:45 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/29 14:18:41 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char		**str;
	int			wd;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	wd = ft_wdcount(s, c);
	if ((str = (char **)ft_memalloc(sizeof(char *) * (wd + 1))) == 0)
		return (NULL);
	while (s[j])
	{
		if ((str[i] = ft_strnew(ft_wdlength(s + j, c))) == 0)
		{
			ft_strdel(str);
			return (NULL);
		}
		ft_wdcopy(str[i], s + j, c, &j);
		i++;
	}
	str[wd] = 0;
	return (str);
}
