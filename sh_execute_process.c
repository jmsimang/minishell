/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execute_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:24:56 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/29 15:52:55 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

/*
** Forks a process and saves the return value. Once fork() returns, we have two
** processes running concurrently. 1. Child process, 2. Parent process.
*/

int			sh_execute_process(char *path, char **args)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		execve(path, args, g_environ);
	else if (pid < 0)
		ft_putendl("fork failed\n");
	wait(&pid);
	return (1);
}

/*
** Checks for access rights to a given path, then executes the process if access
** if OK.
*/

int			sh_execute_process_path(char **args, char **dir)
{
	char	*path;
	int		i;

	i = 0;
	while (dir[i])
	{
		path = ft_strcombine(dir[i], "/", args[0]);
		if (access(path, X_OK) == 0)
		{
			sh_execute_process(path, args);
			free(path);
			return (1);
		}
		free(path);
		i++;
	}
	return (0);
}
