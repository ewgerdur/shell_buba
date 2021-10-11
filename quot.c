/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:42:32 by wgerdur           #+#    #+#             */
/*   Updated: 2021/10/11 19:42:35 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*quot(char *str, int i)
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
}

int	quot_pars(t_mish_save *mish, int *i, char *tmp, int count_args)
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
		pars = quot(pars, 0);
		mish->args = (char **)ft_realloc(mish->args,
				sizeof(char *) * (count_args + 1));
		mish->args[count_args] = ft_strdup(pars);
		ft_lstadd_back_args(&mish->args_lst,
			ft_lstnew_args(ft_strdup(pars), 1));
		free(pars);
		return (1);
	}
	free(pars);
	return (0);
}

int	quot2_pars(t_mish_save *mish, int *i, char *tmp, int count_args)
{
	int		j;
	char	*buba_str;

	j = *i;
	(*i)++;
	while (tmp[*i] && tmp[*i] != '\"')
		(*i)++;
	buba_str = ft_substr(tmp, j, *i - j + 1);
	if (check_spaces(buba_str))
	{
		buba_str = quot2(mish, buba_str, 0);
		mish->args = (char **)ft_realloc(mish->args,
				sizeof(char *) * (count_args
					+ 1));
		mish->args[count_args] = ft_strdup(buba_str);
		ft_lstadd_back_args(&mish->args_lst,
			ft_lstnew_args(ft_strdup(buba_str), 1));
		free(buba_str);
		return (1);
	}
	free(buba_str);
	return (0);
}

char	*quot2(t_mish_save *mish, char *str, int i)
{
	int		j;
	char	*buba_str;

	i++;
	j = i;
	while (str[i] != '\0')
	{
		if (str[i] == '\\' && (str[i + 1] == '\"' || str[i + 1] == '$'
				|| str[i + 1] == '\\' || str[i + 1] == ';'))
			str = ft_slesh(str, &i);
		if (str[i] == '$')
			str = ft_dollar(mish, str, 0, &i);
		if (str[i] == '\"')
			break ;
		i++;
	}
	buba_str = ft_substr(str, j, i - 1);
	free(str);
	return (buba_str);
}

void	quot_check(const char *str, int i, unsigned int *quot_num,
	unsigned int *quot2_num)
{
	if (str[i] == '\'' && *quot2_num % 2 == 0)
	{
		if (i > 0 && str[i - 1] != '\\')
			(*quot_num)++;
		if (i == 0)
			(*quot_num)++;
	}
	if (str[i] == '\"' && *quot_num % 2 == 0)
	{
		if (i > 0 && str[i - 1] != '\\')
			(*quot2_num)++;
		if (i == 0)
			(*quot2_num)++;
	}
}
