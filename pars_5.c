/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:10:45 by wgerdur           #+#    #+#             */
/*   Updated: 2021/10/11 20:10:48 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	void_aae(char **env, char **argv, int argc)
{
	(void)argc;
	(void)argv;
	(void)env;
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

char	*init_variables_pars(t_mish_save *mish, char *str,
		int *i, int *count_args)
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
