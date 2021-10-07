#include "minishell.h"

/*char	*quote(char *str, int i)
{
	int		j;
	char	*tmp;

	j = i;
	while (str[++i])
		if (str[i] == '\'')
			break ;
	tmp = ft_substr(str, j + 1, i - 1);
	free(str);
	return (tmp);
}*/

/*int	quot_pars(int *i, char *tmp, t_ms_save *ms, int count_args)
{
	int		j;
	char	*pars;

	j = *i;
	(*i)++;
	while (tmp[*i] && tmp[*i] != '\'')
		(*i)++;
	pars = ft_substr(tmp, j, *i - j + 1);
	if (check_spaces(pars))
	{
		pars = single_quote(pars, 0);
		ms->args = (char **)ft_realloc(ms->args, sizeof(char *) * (count_args
					+ 1));
		ms->args[count_args] = ft_strdup(pars);
		ft_lstadd_back_args(&ms->args_lst, ft_lstnew_args(ft_strdup(pars), 1));
		free(pars);
		return (1);
	}
	free(pars);
	return (0);
}*/
int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			i++;
	}
	return (i);
}


void	free_lst_mish(t_mish_save *mish, char *str)
{
	if (str == NULL)
	{
		free_list(&mish->env_lst);
		ft_arrfree(mish->env_mish);
		exit(0);
	}
}

void	pipes_correctness_error(void)
{
	ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
	exit_stat = 258;
}