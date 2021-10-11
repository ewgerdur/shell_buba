/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:01:58 by wgerdur           #+#    #+#             */
/*   Updated: 2021/10/11 20:02:00 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*free_strings(char *tmp, char *str)
{
	char	*fr_tmp;

	fr_tmp = ft_substr(str, ft_strlen(tmp), ft_strlen(str));
	free(tmp);
	free(str);
	return (fr_tmp);
}

void	pipes_correctness_error(void)
{
	ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
	g_es = 258;
}
