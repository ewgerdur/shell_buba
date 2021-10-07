#include "minishell.h"

int	set_pwd(t_mish_save *mish)
{
	char	*new;
	char	*tmp;
	char	*pwd;

	tmp = malloc(1024);
	pwd = getcwd(tmp, 1024);
	if (pwd == NULL)
	{
		free(tmp);
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 2);
		return (1);
	}
	new = ft_strjoin("PWD=", pwd);
	new_envp(mish, new);
	free(new);
	free(tmp);
	return (0);
}

int	update_oldpwd(char *old, t_mish_save *mish)
{
	char	*pwd;

	pwd = ft_strjoin("OLDPWD=", old);
	new_envp(mish, pwd);
	free(pwd);
	return (1);
}

int	cd_error(char *dir)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(dir, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	write(2, "\n", 2);
	return (1);
}

int	pwd_changer(char *dir, t_mish_save *mish)
{
	char	*old;
	char	*tmp;

	tmp = ft_calloc(1024, 1);
	if (!tmp)
	{
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 2);
		return (1);
	}
	old = getcwd(tmp, 1024);
	if (chdir(dir) == -1)
	{
		free(tmp);
		return (cd_error(dir));
	}
	free(tmp);
	update_oldpwd(old, mish);
	return (set_pwd(mish));
}

int	cd(t_mish_save *mish, char **args, char **env)
{
	char	*home;
	int		dir_val;

	if (ft_arrlen(args) > 2)
	{
		ft_putstr_fd("minishel>: cd: too many arguments\n", 2);
		return (1);
	}
	else if (ft_arrlen(args) == 1)
	{
		home = find_path("HOME", env);
		if (home == NULL)
		{
			ft_putstr_fd("minishell>: cd : HOME not set \n", 2);
			return (1);
		}
		dir_val = pwd_changer(home, mish);
		free(home);
		return (dir_val);
	}
	else if (ft_arrlen(args) == 2)
		return (pwd_changer(args[1], mish));
	return (0);
}
