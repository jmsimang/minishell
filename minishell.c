/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:03:57 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/29 15:49:22 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

/*
** Launching the shell: This function takes the list of arguments, it then forks
** the process, and saves the return value.
*/

static int	launch_process(char **cmd)
{
	char	**dir;
	int		result;

	if (access(cmd[0], X_OK) == 0)
	{
		sh_execute_process(cmd[0], cmd);
		return (1);
	}
	dir = ft_strsplit(sh_get_environment("PATH"), ':');
	if (!dir || dir[0] == NULL)
		ft_putendl(ft_strjoin(cmd[0], ": command not found"));
	else
	{
		result = sh_execute_process_path(cmd, dir);
		if (result == 0)
			ft_putendl(ft_strjoin(cmd[0], ": command not found"));
	}
	ft_strdel(dir);
	return (1);
}

/*
** Checks if the command equals each builtin, and if so, run it. If it doesn't
** match a builtin, it calls launch_process() to launch a process. CMD might
** just contain NULL, if imput is an empty string, or a space, it checks for
** that case at the beginning.
*/

static int	run_command(char **cmd)
{
	if (!cmd || !*cmd)
		return (1);
	else if (ft_strcmp(cmd[0], "echo") == 0)
		return (sh_echo(cmd + 1));
	else if (ft_strcmp(cmd[0], "cd") == 0)
		return (sh_cd(cmd + 1));
	else if (ft_strcmp(cmd[0], "setenv") == 0)
		return (sh_setenv(cmd + 1));
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		return (sh_unsetenv(cmd + 1));
	else if (ft_strcmp(cmd[0], "env") == 0)
	{
		sh_environment();
		return (1);
	}
	else if (!ft_strcmp(cmd[0], "exit"))
		return (sh_exit(cmd));
	else
		return (launch_process(cmd));
}

/*
** Basic loop of a shell (runs while loop equals 1):
** 1. Read: Reads command from standard input.
** 2. Parse: Separates the command string into a program and arguments.
** 3. Execute: Run the parsed command.
*/

static void	loop_shell(void)
{
	int		loop;
	char	*line;
	char	**cmd;

	loop = 1;
	while (loop)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		cmd = ft_tokenize(line);
		loop = run_command(cmd);
		ft_strdel(&line);
		ft_strdel(cmd);
	}
}

/*
** Main program saves a copy of the environment variables to a global variable
** runs a basic shell on loop, then frees the
** allocated memory global.
*/

int			main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	initiate_environment(env);
	loop_shell();
	free(g_environ);
	return (0);
}
