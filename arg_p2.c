#include "minishell.h"

char	*free_sle(char *str, int j, int *i)
{
	char	*new;
	char	*tmp;
	char	*prev;

	new = ft_substr(str, 0, j);
	prev = ft_substr(str, j + 1, *i - j - 1);
	tmp = ft_strjoin(new, prev);
	free(new);
	free(prev);
	return (tmp);
}

char	*ft_sle2(t_mish_save *mish, char *str, int *i)
{
	int		j;
	char	*new;

	j = *i;
	while (str[*i])
	{
		if (str[*i] == '\\' && (str[*i + 1] == '\"' || str[*i + 1] == '$'
				|| str[*i + 1] == '\\' || str[*i + 1] == ';'))
			str = ft_slesh(str, i);
		if (str[*i] == '$')
		{
			str = ft_dollar(mish, str, 0, i);
			(*i) = -1;
		}
		if (str[*i] == '\"')
			break ;
		(*i)++;
	}
	new = free_sle(str, j, i);
	free(str);
	return (new);
}

char	*parser(t_mish_save *mish, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
		{
			str = ft_sle2(mish, str, &i);
			i = -1;
		}
		if (str[i] == '\'' && ft_strlen(str) > 1)
		{
			str = ft_sle(str, &i);
			i = -1;
		}
		if (str[i] == '\\')
			str = ft_slesh(str, &i);
		/*if (str[i] == '\"')
		{
			str = ft_gap2(mish, str, &i);
			i = -1;
		}*/
		if (str[i] == '$' && ft_strlen(str) > 1)
		{
			str = ft_dollar(mish, str, 0, &i);
			i = -1;
		}
		i++;
	}
	return (str);
}
