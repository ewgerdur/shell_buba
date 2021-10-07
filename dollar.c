
#include "minishell.h"

char	*free_dollar(char *first_part, char *second_part, char *new)
{
	char	*tmp;
	char	*tmp2;

	tmp = new;
	new = ft_strjoin(first_part, new);
	free(tmp);
	tmp2 = new;
	new = ft_strjoin(new, second_part);
	free(tmp2);
	free(first_part);
	free(second_part);
	return (new);
}

static void	check_dollar(t_mish_save *mish, char *str, int *i)
{
	if (ft_strlen(str) == 2 && str[*i] == '$' && str[(*i) + 1] == '?')
		question_mark(mish);
	while (str[++(*i)])
		if (!k_search(str[*i]))
			break ;
}

char	*null_dollar(char *first_part, char *second_part)
{
	char	*new;
	char	*tmpd;

	new = ft_strjoin(first_part, "");
	tmpd = new;
	new = ft_strjoin(new, second_part);
	free(tmpd);
	free(first_part);
	free(second_part);
	return (new);
}

char	*ft_dollar(t_mish_save *mish, char *str, int j, int *i)
{
	char	*tmp;
	char	*new;
	char	*first_part;
	char	*second_part;

	j = *i;
	if ((ft_strlen(str) == 1 && str[*i] == '$') || (ft_strlen(str) > 1
			&& str[*i] == '$' && str[(*i) + 1] == ' '))
		return (str);
	check_dollar(mish, str, i);
	tmp = ft_substr(str, j + 1, *i - j - 1);
	first_part = ft_substr(str, 0, j);
	second_part = ft_substr(str, *i, ft_strlen(str) - (*i - j - 1));
	new = find_path(tmp, mish->env_mish);
	free(tmp);
	if (new == NULL)
		return (null_dollar(first_part, second_part));
	new = free_dollar(first_part, second_part, new);
	(*i) = j;
	free(str);
	return (new);
}
