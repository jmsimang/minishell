/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:25:31 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/29 16:48:00 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_words(char *s)
{
	size_t	length;

	length = 0;
	while (*s)
	{
		while (*s && ((*s >= 9 && *s <= 13) || *s == 32))
			s++;
		if (*s && (!(*s >= 9 && *s <= 13) && *s != 32))
		{
			length++;
			while (*s && (!(*s >= 9 && *s <= 13) && *s != 32))
				s++;
		}
	}
	return (length);
}

static char	*ft_create_token(char *s)
{
	char	*token;
	size_t	i;

	i = 0;
	while (s[i] && (!(s[i] >= 9 && s[i] <= 13) && s[i] != ' '))
		i++;
	token = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (s[i] && (!(s[i] >= 9 && s[i] <= 13) && s[i] != 32))
	{
		token[i] = s[i];
		i++;
	}
	token[i] = '\0';
	return (token);
}

char		**ft_tokenize(char *s)
{
	size_t	i;
	int		wdlength;
	char	**tokens;

	i = 0;
	wdlength = ft_words(s);
	tokens = (char **)malloc(sizeof(char *) * wdlength + 1);
	while (*s)
	{
		while (*s && ((*s >= 9 && *s <= 13) || *s == ' '))
			s++;
		if (*s && (!(*s >= 9 && *s <= 13) && *s != ' '))
		{
			tokens[i] = ft_create_token(s);
			i++;
			while (*s && (!(*s >= 9 && *s <= 13) && *s != ' '))
				s++;
		}
	}
	tokens[i] = NULL;
	return (tokens);
}
