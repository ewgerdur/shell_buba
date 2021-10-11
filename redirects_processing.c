/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:43:05 by wgerdur           #+#    #+#             */
/*   Updated: 2021/10/11 19:43:07 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cycle_read(t_mish_save *mish, t_buba *lst, char *stop)
{
	char	*str;

	(void)mish;
	while (1)
	{
		str = readline("> ");
		if (!ft_strncmp(str, stop, ft_strlen(stop) + 1))
			break ;
		ft_putendl_fd(str, lst->out);
		free(str);
	}
	close(lst->out);
	exit(0);
}

static void	dl_redir(t_mish_save *mish, t_buba *lst, char *stop)
{
	int	fd[2];
	int	pid;

	if (lst->in)
		close(lst->in);
	if (pipe(fd) < 0)
	{
		if (lst->fork)
			pipe_err(0, 0, 0);
		else
			err(NULL, NULL);
	}
	pid = fork();
	if (pid)
	{
		waitpid(pid, 0, 0);
		lst->in = fd[0];
		close(fd[1]);
	}
	else
	{
		close(fd[0]);
		lst->out = fd[1];
		cycle_read(mish, lst, stop);
	}
}

static void	red_check_for_pars(t_mish_save *mish, t_buba *lst, int i, int j)
{
	char	*buf;

	buf = file_name_export(lst->redir[i], j);
	if (j == 1)
	{
		if (lst->in != 0)
			close(lst->in);
		lst->in = open(buf, O_RDONLY);
	}
	else if (j == 2)
	{
		if (lst->out != 1)
			close(lst->out);
		lst->out = open(buf, O_WRONLY | O_CREAT | O_TRUNC, 00774);
	}
	else if (j == 3)
	{
		if (lst->out != 1)
			close(lst->out);
		lst->out = open(buf, O_WRONLY | O_CREAT | O_APPEND, 00774);
	}
	else if (j == 4)
		dl_redir(mish, lst, buf);
	redir_err(lst, buf);
	free(buf);
}

static void	redir_dup(t_buba *lst)
{
	if (lst->in != 0)
	{
		if (dup2(lst->in, 0) < 0)
		{
			if (lst->fork)
				pipe_err(0, 0, 0);
			else
				err(0, 0);
		}
		close(lst->in);
	}
	if (lst->out != 1)
	{
		if (dup2(lst->out, 1) < 0)
		{
			if (lst->fork)
				pipe_err(0, 0, 0);
			else
				err(0, 0);
		}
		close(lst->out);
	}
}

int	redir_pars(t_mish_save *mish, t_buba *lst, int j)
{
	int	i;

	i = 0;
	lst->fork = j;
	while (lst->redir[i])
	{
		if (lst->redir[i][0] == '<' && lst->redir[i][1] != '<')
			red_check_for_pars(mish, lst, i, 1);
		else if (lst->redir[i][0] == '>' && lst->redir[i][1] != '>')
			red_check_for_pars(mish, lst, i, 2);
		else if (lst->redir[i][0] == '>' && lst->redir[i][1] == '>')
			red_check_for_pars(mish, lst, i, 3);
		else if (lst->redir[i][0] == '<' && lst->redir[i][1] == '<')
			red_check_for_pars(mish, lst, i, 4);
		i++;
	}
	if (g_es == 0)
		redir_dup(lst);
	return (g_es);
}
