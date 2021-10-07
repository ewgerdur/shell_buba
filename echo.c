#include "minishell.h"

int	n_checker(const char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	echo_handler(char **str)
{
	int	n_flag;
	int	i;

	n_flag = 0;
	i = 1;
	if (ft_arrlen(str) == 1)
	{
		write(1, " \n", 2);
		return (0);
	}
	while (str[i])
	{
		if (!(ft_strncmp(str[i], "-n", 2)) && n_checker(str[i]))
			n_flag = 1;
		else
		{
			write(1, str[i], ft_strlen(str[i]));
			if (str[i + 1])
				write(1, " ", 1);
		}
		i++;
	}
	if (n_flag == 0)
		write(1, "\n", 1);
	return (0);
}
