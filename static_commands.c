#include "minishell.h"

int	pwd(void)
{
	char	*pwd;

	pwd = ft_calloc(4096, 1);
	if (getcwd(pwd, 4096))
	{
		ft_putstr_fd(pwd, 1);
		free(pwd);
		write(1, "\n", 1);
		return (0);
	}
	ft_putstr_fd(strerror(errno), 2);
	write(2, "\n", 2);
	free(pwd);
	return (1);
}

int	env(t_mish_save *mish)
{
	t_list	*envp;

	envp = mish->env_lst;
	while (envp)
	{
		if (ft_strchr(envp->content, '='))
		{
			ft_putstr_fd(envp->content, 1);
			ft_putstr_fd("\n", 1);
		}
		envp = envp->next;
	}
	return (0);
}

int	name_check(t_buba *lst)
{
	if (ft_arrlen(lst->args) > 0)
	{
		if (!ft_strncmp(lst->args[0], "echo", ft_strlen(lst->args[0])))
			return (0);
		else if (!ft_strncmp(lst->args[0], "cd", ft_strlen(lst->args[0])))
			return (0);
		else if (!ft_strncmp(lst->args[0], "pwd", ft_strlen(lst->args[0])))
			return (0);
		else if (!ft_strncmp(lst->args[0], "export", ft_strlen(lst->args[0])))
			return (0);
		else if (!ft_strncmp(lst->args[0], "unset", ft_strlen(lst->args[0])))
			return (0);
		else if (!ft_strncmp(lst->args[0], "exit", ft_strlen(lst->args[0])))
			return (0);
		else if (!ft_strncmp(lst->args[0], "env", ft_strlen(lst->args[0])))
			return (0);
	}
	return (1);
}

void	name_exec_check(t_mish_save *mish, t_buba *lst)
{
	if (!ft_strncmp(lst->args[0], "echo", ft_strlen(lst->args[0])))
		exit_stat = echo_handler(lst->args);
	else if (!ft_strncmp(lst->args[0], "cd", ft_strlen(lst->args[0])))
		exit_stat = cd(mish, lst->args, mish->env_mish);
	else if (!ft_strncmp(lst->args[0], "pwd", ft_strlen(lst->args[0])))
		exit_stat = pwd();
	else if (!ft_strncmp(lst->args[0], "export", ft_strlen(lst->args[0])))
		exit_stat = export(mish, lst->args);
	else if (!ft_strncmp(lst->args[0], "unset", ft_strlen(lst->args[0])))
		exit_stat = unset(mish, lst->args);
	else if (!ft_strncmp(lst->args[0], "exit", ft_strlen(lst->args[0])))
		exit_stat = exit_mish(mish, lst->args);
	else if (!ft_strncmp(lst->args[0], "env", ft_strlen(lst->args[0])))
		exit_stat = env(mish);
}
