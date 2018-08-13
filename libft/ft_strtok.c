/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 13:36:36 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/18 09:44:01 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtok(char *str, char delim)
{
	static char	*token;
	char		*ptr;
	int			i;

	i = 0;
	ptr = NULL;
	if (str != NULL)
		token = ft_strdup(str);
	while (*token)
	{
		if (i == 0 && (*token != delim || !(*token >= 9 && *token <= 13)))
		{
			i = 1;
			ptr = token;
		}
		else if (i == 1 && (*token == delim || (*token > 8 && *token < 14)))
		{
			*token = '\0';
			token += 1;
			break ;
		}
		token++;
	}
	return (ptr);
}
