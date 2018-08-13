/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_environment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:32:58 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/29 15:52:05 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

/*
** Makes a copy of the current environment variables and copies these to the
** global variable g_environ. With each command, a new copy is made.
*/

void		initiate_environment(char **env)
{
	int		i;

	i = 0;
	while (env[i])
		i++;
	g_environ = (char **)malloc(sizeof(char *) * i + 1);
	i = -1;
	while (env[++i])
	{
		if (!(g_environ[i] = ft_strdup(env[i])))
		{
			ft_strdel(g_environ);
			ft_putchar('\n');
			exit(0);
		}
	}
	g_environ[i] = NULL;
}

/*
** Retrieves an environment variable based on an equality check of the
** variable given and what's available on the system. If nothing is found, it
** returns NULL.
*/

char		*sh_get_environment(char *path)
{
	int		index;
	char	*temp;

	index = 0;
	while (g_environ[index])
	{
		temp = ft_strjoin(path, "=");
		if (ft_strunequ(g_environ[index], temp))
		{
			free(temp);
			return (ft_strchr(g_environ[index], '=') + 1);
		}
		free(temp);
		index++;
	}
	return (NULL);
}

/*
** Function prints out all system environment variables.
*/

void		sh_environment(void)
{
	int		index;

	index = -1;
	while (g_environ[++index])
		ft_putendl(g_environ[index]);
	return ;
}
