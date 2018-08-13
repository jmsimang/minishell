/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:35:50 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/29 16:26:18 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
**<sys/wait.h> //waitpid() and associated macros
**<unistd.h> //chdir(), fork(), exec(), pid_t, execve()
*/

# include <sys/wait.h>
# include <unistd.h>
# include "libft.h"
# define BUF_SIZE 32
# define MAX_BUFF_SIZE 2048

char		**g_environ;

void		initiate_environment(char **env);
char		*sh_get_environment(char *path);
int			sh_exit(char **args);
int			sh_echo(char **args);
int			sh_cd(char **args);
int			sh_setenv(char **args);
int			sh_unsetenv(char **args);
void		sh_environment(void);
int			sh_execute_process(char *path, char **args);
int			sh_execute_process_path(char **args, char **dir);
char		**realloc_env(int size);
int			get_pos(char *e_var);
void		create_variable(char *e_var, char *e_val);

#endif
