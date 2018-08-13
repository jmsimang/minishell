/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:01:19 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/29 15:51:29 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

/*
** Checks whether a given environment variable exists, if it does not, it
** displays an error, else it echoes the variable.
*/

static void	check_command(char *path)
{
	if (sh_get_environment(path) == NULL)
		ft_putstr(ft_strcombine("$", path, ": variable not found"));
	else
	{
		ft_putstr(sh_get_environment(path));
		free(path);
	}
}

/*
** Echoes a command, provides error checking for the given command, then outputs
** the results of the echo command.
*/

static void	echo_command(char *cmd)
{
	int		len;
	int		i;
	int		j;
	char	*path;

	len = (int)ft_strlen(cmd);
	i = 0;
	j = len - 1;
	if (cmd[0] == '$')
	{
		path = ft_strdup(cmd + 1);
		check_command(path);
	}
	else
	{
		while (cmd[i] == '\'' || cmd[i] == '"')
			i++;
		while (cmd[j] == '\'' || cmd[j] == '"')
			j--;
		while (i <= j)
			ft_putchar(cmd[i++]);
	}
	ft_putchar(' ');
}

/*
** Checks the given echo command for any discrepencies, then calls the relevant
** functions to execute the echo command.
*/

int			sh_echo(char **cmd)
{
	int		i;

	if (!cmd[0])
	{
		ft_putchar('\n');
		return (1);
	}
	i = 0;
	while (cmd[i])
	{
		if (cmd[i])
			echo_command(cmd[i]);
		i++;
	}
	ft_putchar('\n');
	return (1);
}
