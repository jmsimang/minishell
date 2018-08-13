/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:01:47 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/29 16:26:16 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

/*
** Checks an environment variable with the global variable list, if found, it
** returns the index of the variable.
*/

int			get_pos(char *e_var)
{
	int		i;
	char	*temp;

	i = -1;
	while (g_environ[++i])
	{
		temp = ft_strjoin(e_var, "=");
		if (ft_strunequ(g_environ[i], temp))
		{
			free(temp);
			return (i);
		}
		free(temp);
	}
	return (i);
}

/*
** Reallocates memory to the g_environ variable, then return a fresh
** null-terminated variable to be used by the calling function.
*/

char		**realloc_env(int size)
{
	int		i;
	char	**env;

	i = 0;
	env = (char **)ft_memalloc(sizeof(char *) * size + 1);
	while (g_environ[i] && i < size)
	{
		env[i] = ft_strdup(g_environ[i]);
		free(g_environ[i]);
		i++;
	}
	env[i] = NULL;
	free(g_environ);
	return (env);
}

/*
** Accepts a variable name and value given by the sh_setenv function then checks
** checks whether the variable exists, if it does, it clears it then assigns a
** new value to it, if not, it creates it and adds it to the g_environ variable.
*/

void		create_variable(char *e_var, char *e_val)
{
	int		pos;

	pos = get_pos(e_var);
	if (g_environ[pos])
	{
		free(g_environ[pos]);
		if (e_val)
			g_environ[pos] = ft_strjoin(e_var, ft_strjoin("=", e_val));
	}
	else
	{
		g_environ = realloc_env(pos + 1);
		if (e_val)
			g_environ[pos] = ft_strjoin(e_var, ft_strjoin("=", e_val));
		g_environ[pos + 1] = NULL;
	}
}

/*
** Performs checks on the arguments given when the 'setenv' command is entered
** by the user. It the input is correct, it parses the variable name and value
** to the create_variable function.
*/

int			sh_setenv(char **args)
{
	if (!args[0] || (args[0] && !args[1]))
	{
		ft_putendl("setenv: missing parameter");
		return (1);
	}
	if (args[0] && args[1])
	{
		if (args[2])
		{
			ft_putendl("setenv: command only accepts two parameters");
			return (1);
		}
		create_variable(args[0], args[1]);
	}
	return (1);
}
