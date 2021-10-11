/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:31:23 by wgerdur           #+#    #+#             */
/*   Updated: 2021/10/11 19:31:32 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_err(char *str, char *error_message, int err)
{
	if (str)
		ft_putendl_fd(str, 2);
	else
		perror(error_message);
	if (err)
		exit(err);
	else if (errno)
		exit(errno);
	else
		exit(1);
}

void	err(char *str, char *error_message)
{
	if (str)
		ft_putendl_fd(str, 2);
	else
		perror(error_message);
	if (errno)
		g_es = errno;
	else
		g_es = 1;
}

void	redir_err(t_buba *lst, char *file_name)
{
	if (lst->in < 0 || lst->out < 0)
	{
		if (lst->fork)
			pipe_err(NULL, file_name, 1);
		else
			err(NULL, file_name);
	}
}

void	synt_err(const char *str, int i)
{
	if ((str[i] == ';' && str[i + 1] == ';')
		|| (str[i] == '|' && str[i + 1] == ';')
		|| (str[i] == ';' && str[i + 1] == '|'))
	{
		ft_putstr_fd("parse error near `;;'\n", 2);
		g_es = 258;
	}
}

void	quot_err(const char *str, int i, unsigned int quot_num,
						 unsigned int quot2_num)
{
	if (quot_num % 2 != 0 || quot2_num % 2 != 0)
	{
		ft_putstr_fd("Incorrect number of quotes or dquotes\n", 2);
		g_es = 1;
	}
	if (str[i - 1] == '\\')
	{
		ft_putstr_fd("Slash is on the end of the line\n", 2);
		g_es = 1;
	}
}
