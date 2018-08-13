/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 19:13:34 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/28 16:37:21 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*ft_add_last_char(char const *s1, char c)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!s1 || !c)
		return (NULL);
	len = ft_strlen(s1);
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	return (str);
}

static int		ft_c(char **dest, char *src, char c)
{
	int index;
	int ch;
	int p;

	index = 0;
	ch = 0;
	while (src[index])
	{
		if (src[index] == c)
			break ;
		index++;
	}
	p = index;
	if ((*dest = ft_strnew(index)) == NULL)
		return (0);
	while (*src && ch < index)
	{
		if ((*dest = ft_add_last_char(*dest, src[ch])) == NULL)
			return (0);
		ch++;
	}
	return (p);
}

static t_list	*ft_get_file(t_list **file, int fd)
{
	t_list *current;

	current = *file;
	while (current != NULL)
	{
		if ((int)current->content_size == fd)
			return (current);
		current = current->next;
	}
	current = ft_lstnew("\0", fd);
	ft_lstadd(file, current);
	current = *file;
	return (current);
}

int				get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	static t_list	*file;
	size_t			index;
	size_t			res;
	t_list			*current;

	if (fd < 0 || line == NULL || read(fd, buffer, 0) < 0)
		return (-1);
	current = ft_get_file(&file, fd);
	while ((res = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[res] = '\0';
		current->content = ft_strjoin(current->content, buffer);
		if (current->content == NULL)
			return (-1);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (res < BUFF_SIZE && (ft_strlen(current->content) == 0))
		return (0);
	index = ft_c(line, current->content, '\n');
	index < ft_strlen(current->content) ? current->content += (index + 1) :
		ft_strclr(current->content);
	return (1);
}
