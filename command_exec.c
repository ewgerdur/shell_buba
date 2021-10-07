
#include "minishell.h"

void	exec_binary(t_mish_save *mish, t_buba *lst)
{
	char	*path;
	char	*tmp;
	char	*exec_path;

	exec_path = NULL;
	exec_path = path_operations(mish->env_mish, lst->args, &path,
			&tmp);
	if (exec_path == NULL)
	{
		ft_putstr_fd(lst->args[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		free(exec_path);
		exit(127);
	}
	if (execve(exec_path, lst->args, mish->env_mish) == -1)
	{
		free(exec_path);
		ft_putstr_fd("Execute error\n", 1);
		exit(127);
	}
	free(exec_path);
}

void	ft_execut(t_mish_save *mish, t_buba *lst)
{
	lst->pid = fork();
	if (lst->pid == 0)
	{
		signal_child();
		if (lst->next)
			close(lst->next->in);
		redir_pars(mish, lst, 1);
		dup2(lst->in, 0);
		dup2(lst->out, 1);
		if (!name_check(lst))
		{
			name_exec_check(mish, lst);
			exit(exit_stat);
		}
		else
			exec_binary(mish, lst);
	}
	if (lst->out != 1)
		close(lst->out);
	if (lst->in != 0)
		close(lst->in);
	if (lst->pid < 0)
	{
		err(0, "Fork problem: ");
		exit_stat = 128;
	}
}

void	ft_if(t_mish_save *mish, t_buba *lst)
{
	ft_execut(mish, lst);
	if (exit_stat == 0)
	{
		waitpid(lst->pid, &mish->stat_exec, 0);
		exit_stat = WEXITSTATUS(mish->stat_exec);
		if (exit_stat == 0 && WIFSIGNALED(mish->stat_exec))
		{
			if (mish->stat_exec == 2 || mish->stat_exec == 3)
				ft_putendl_fd("", 2);
			exit_stat = 128 + WTERMSIG(mish->stat_exec);
		}
	}
}

void	last_exec(t_mish_save *mish, t_buba *lst)
{
	if (!name_check(lst))
	{
		save_dups(mish);
		if (!redir_pars(mish, lst, 0))
			name_exec_check(mish, lst);
		close(lst->in);
		close(1);
		if (dup2(mish->mish_in, 0) < 0)
			err(0, 0);
		if (dup2(mish->mish_out, 1) < 0)
			err(0, 0);
		close(mish->mish_in);
		close(mish->mish_out);
	}
	else
	{
		ft_if(mish, lst);
	}
}

void	pid_waiting(t_buba *start, t_buba *lst)
{
	t_buba	*first;

	first = start;
	while (first && first->next && first != lst)
	{
		close(first->fd[1]);
		close(first->fd[0]);
		first = first->next;
	}
	first = start;
	while (first && first->next && first != lst)
	{
		if (first->next)
			waitpid(first->pid, 0, 0);
		first = first->next;
	}
}
