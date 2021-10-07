#include "minishell.h"

int	compare_strings(char *str, char *tmp)
{
	int	i;

	i = 0;
	while (str[i] == tmp[i] && str[i] && tmp[i])
		i++;
	if (str[i] == tmp[i])
		return (0);
	return (str[i] - tmp[i]);
}

void	print_declare(char **env)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		j = 0;
		ft_putstr_fd("declare -x ", 1);
		while (env[i][j] != '=')
		{
			write(1, &env[i][j], 1);
			j++;
		}
		write(1, &env[i][j], 1);
		j++;
		write(1, "\"", 1);
		while (env[i][j])
		{
			write(1, &env[i][j], 1);
			j++;
		}
		write(1, "\"", 1);
		write(1, "\n", 1);
		i++;
	}
}

int	check_arg_export(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '=' || ft_isdigit(arg[0]) || !ft_isalpha(arg[0]))
	{
		write(2, "export: '", 10);
		write(2, arg, ft_strlen(arg));
		write(2, "': not a valid identifier\n", 26);
		return (0);
	}
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalpha(arg[i]) && !ft_isdigit(arg[i]))
		{
			write(2, "export: '", 10);
			write(2, arg, ft_strlen(arg));
			write(2, "': not a valid identifier\n", 26);
			return (0);
		}
		i++;
	}
	return (1);
}

int	export(t_mish_save *mish, char **args)
{
	int	i;

	i = 1;
	if (ft_arrlen(args) == 1)
	{
		sort_env(mish);
		print_declare(mish->env_mish);
		return (0);
	}
	while (args[i])
	{
		if (check_arg_export(args[i]))
			new_envp(mish, args[i]);
		else
			return (1);
		i++;
	}
	return (0);
}

int	unset(t_mish_save *mish, char **args)
{
	int		i;
	t_list	*env;

	i = 1;
	if (args[1] == NULL)
		return (1);
	while (args[i])
	{
		env = mish->env_lst;
		while (env && env->next)
		{
			if (args[i][0] != '\0')
				remove_elem(mish, args[i]);
			env = env->next;
		}
		i++;
	}
	return (1);
}
