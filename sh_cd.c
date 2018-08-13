/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:40:01 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/29 16:26:21 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

/*
** Implements the functionality of the 'cd' command. It first checks the path,
** performs error handling, and then does the necessary operations.
*/

static void	sh_chdir(char *path)
{
	char	*c_dir;
	char	buff[MAX_BUFF_SIZE];

	c_dir = getcwd(buff, MAX_BUFF_SIZE - 1);
	if (!chdir(path))
		create_variable("OLDPWD", c_dir);
	else
	{
		if (access(path, F_OK) == -1 && path[0] == '$')
			ft_putstr("");
		else if (access(path, F_OK) == -1)
		{
			ft_putstr(ft_strjoin("cd: ", path));
			ft_putendl(": no such file or directory");
		}
		else if (access(path, R_OK) == -1)
			ft_putendl(ft_strcombine("cd ", path, ": permission denied"));
		else
			ft_putendl(ft_strcombine("cd ", path, ": not a directory"));
	}
}

/*
** Joins the HOME directory path with a given directory, then changes to it.
*/

static void	home_dir(char *path, char *args)
{
	char	*tmp_path;

	args++;
	args++;
	tmp_path = ft_strjoin(path, args);
	sh_chdir(tmp_path);
	free(tmp_path);
}

/*
** Performs checks of a 'cd' command and checks the given arguments, if any,
** then calls the chdir() function to perform the operation. $ sign
** functionality when using environment variables.
*/

int			sh_cd(char **args)
{
	char	*path;

	path = sh_get_environment("HOME");
	if (!args[0] || (args[0][0] == '~' && !args[0][1]))
		sh_chdir(path);
	else
	{
		if (args[0][0] == '~' && args[0][1] == '/')
		{
			home_dir(ft_strjoin(path, "/"), args[0]);
			return (1);
		}
		else if (args[0][0] == '~' && !(args[0][1]))
		{
			sh_chdir(sh_get_environment("OLDPWD"));
			return (1);
		}
		else if (args[0][0] == '$')
		{
			path = ft_strdup(args[0]);
			sh_chdir(sh_get_environment(++path));
		}
		sh_chdir(args[0]);
	}
	return (1);
}
