/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:02:06 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/29 16:09:55 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

/*
** Removes an environment variables from the shell's global variable list, it
** copies another variable in its position, then reallocates the g_environ
** variable with the new size.
*/

static void	clear_env(int pos)
{
	int		i;
	int		count;

	ft_putendl(ft_strjoin(g_environ[pos], " : removed"));
	free(g_environ[pos]);
	g_environ[pos] = NULL;
	i = pos;
	count = pos + 1;
	while (g_environ[i + 1])
	{
		g_environ[i] = ft_strdup(g_environ[i + 1]);
		free(g_environ[i + 1]);
		i++;
		count++;
	}
	g_environ = realloc_env(count - 1);
}

/*
** Takes an environment variable name and checks whether it exists, it it does
** it then calls the clear_env function to remove it.
*/

int			sh_unsetenv(char **args)
{
	int		pos;
	int		i;

	if (!args[0])
	{
		ft_putendl("unsetenv: missing parameter");
		return (1);
	}
	i = -1;
	while (args[++i])
	{
		pos = get_pos(args[i]);
		if (g_environ[pos])
			clear_env(pos);
	}
	return (1);
}
