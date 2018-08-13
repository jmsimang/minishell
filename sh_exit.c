/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmsimang <jmsimang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:22:20 by jmsimang          #+#    #+#             */
/*   Updated: 2017/09/29 15:36:20 by jmsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

/*
**Basic built-in that disallows the use of exit() with more than 1 argument.
*/

int			sh_exit(char **cmd)
{
	if (cmd[1] && cmd[2])
	{
		ft_putendl(ft_strjoin(cmd[0], ": too many arguments"));
		return (1);
	}
	else if ((!(cmd[1]) && !cmd[2]) || (cmd[1] && !cmd[2]))
		return (0);
	else
		return (0);
}
