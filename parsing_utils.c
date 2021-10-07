#include "minishell.h"

int	char_in_string(char ch, char *chars)
{
	while (*chars)
		if (*chars++ == ch)
			return (1);
	return (0);
}

int	check_spaces(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (*str == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (ft_strlen(str) == 0 || ft_strlen(str) == i)
		return (0);
	return (1);
}

int	lash(const char *tmp, int *i)
{
	if (tmp[*i] == '\\')
	{
		(*i) += 2;
		return (1);
	}
	return (0);
}

char	*free_strings(char *tmp, char *str)
{
	char	*fr_tmp;

	fr_tmp = ft_substr(str, ft_strlen(tmp), ft_strlen(str));
	free(tmp);
	free(str);
	return (fr_tmp);
}

char	*init_variables_pars(t_mish_save *mish, char *str, int *i, int *count_args)
{
	char	*tmp;

	tmp = ft_substr(str, 0, *i);
	(*i) = 0;
	(*count_args) = 0;
	if (tmp[*i] == '|')
		(*i)++;
	while (tmp[*i] && (tmp[*i] == ' ' || tmp[*i] == '\t' || tmp[*i] == '|'))
		(*i)++;
	mish->args = (char **)malloc(sizeof(char *));
	mish->redirs = (char **)malloc(sizeof(char *));
	if (mish->args == NULL || mish->redirs == NULL)
	{
		ft_putstr_fd("Malloc exception\n", 2);
		exit(errno);
	}
	return (tmp);
}
