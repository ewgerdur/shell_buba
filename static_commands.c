#include "minishell.h"

int	pwd(t_mish_save *mish)
{
	t_list	*envp;

	envp = mish->env_lst;
	while (envp)
	{
		if (!ft_strncmp(envp->content, "PWD=", 4))
		{
			ft_putstr_fd(envp->content + 4, 1);
			ft_putstr_fd("\n", 1);
		}
		envp = envp->next;
	}
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
		g_es = echo_handler(lst->args);
	else if (!ft_strncmp(lst->args[0], "cd", ft_strlen(lst->args[0])))
		g_es = cd(mish, lst->args, mish->env_mish);
	else if (!ft_strncmp(lst->args[0], "pwd", ft_strlen(lst->args[0])))
		g_es = pwd(mish);
	else if (!ft_strncmp(lst->args[0], "export", ft_strlen(lst->args[0])))
		g_es = export(mish, lst->args);
	else if (!ft_strncmp(lst->args[0], "unset", ft_strlen(lst->args[0])))
		g_es = unset(mish, lst->args);
	else if (!ft_strncmp(lst->args[0], "exit", ft_strlen(lst->args[0])))
		g_es = exit_mish(mish, lst->args);
	else if (!ft_strncmp(lst->args[0], "env", ft_strlen(lst->args[0])))
		g_es = env(mish);
}
