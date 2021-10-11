#include "minishell.h"

static int	num_checker(char *args)
{
	int	i;
	int	symbol;

	symbol = 0;
	i = 0;
	if (args[i] == '+' || args[i] == '-')
	{
		symbol = 1;
		i++;
	}
	if ((int) ft_strlen(args) > 21 + symbol)
		return (1);
	while (args[i])
	{
		if (ft_isdigit(args[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

static int	exit_atoi(char *str)
{
	int			i;
	int			minus;
	int			num;

	i = 0;
	minus = 1;
	num = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i])
		num = (num * 10) + (str[i++] - '0');
	return (num * minus);
}

int	exit_mish(t_mish_save *mish, char **args)
{
	if (args[1] == NULL)
		exit(mish->stat_buba);
	if (num_checker(args[1]))
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd(": numeric argument required", 2);
		ft_putstr_fd("\n", 2);
		exit(255);
	}
	if (ft_arrlen(args) > 2)
	{
		ft_putstr_fd("exit: ", 2);
		ft_putstr_fd("too many arguments", 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	else if (ft_arrlen(args) == 2)
		exit(exit_atoi(args[1]));
		exit(ft_atoi(args[1]));
	return (0);
}
