/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:45:16 by wgerdur           #+#    #+#             */
/*   Updated: 2021/10/11 19:45:18 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_start_pars2(t_mish_save *mish, t_buba **head, char *str, int i)
{
	char	*tmp;
	int		count_args;
	int		count_redir;

	tmp = init_variables_pars(mish, str, &i, &count_args);
	count_redir = 0;
	mish->args_lst = NULL;
	while (tmp[i] && g_es == 0)
	{
		if (tmp[i] == '\"' && (!char_in_string(tmp[i], " <>\n\t\0") || tmp[i]
				== '\\'))
			count_args += quot2_pars(mish, &i, tmp, count_args);
		else if (tmp[i] && (tmp[i] == '>' || tmp[i] == '<'))
			count_redir = redir_parser(mish, &i, tmp, count_redir);
		else if (tmp[i] == '\'' && (!char_in_string(tmp[i], " <>\n\t\0")))
			count_args += quot_pars(mish, &i, tmp, count_args);
		else if (!char_in_string(tmp[i], " <>\n\t\0") || tmp[i] == '\\')
			count_args += ca_pars(mish, &i, tmp, count_args);
		i++;
	}
	if (count_args == 0 && count_redir == 0 && g_es == 0)
		pipes_correctness_error();
	struct_lists_creating(mish, head, count_redir, count_args);
	i = 0;
	return (free_strings(tmp, str));
}

int	ft_start_pars1(t_mish_save *mish, char *str,
	t_buba **head, unsigned int part)
{
	unsigned int	quot_num;
	unsigned int	quot2_num;
	int				i;

	quot_num = 0;
	quot2_num = 0;
	i = 0;
	while (str[i] && str[i] == ' ')
		return (0);
	while (str[i] && g_es == 0 && ++part)
	{
		synt_err(str, i);
		if (str[i] == '|' && quot_num % 2 == 0 && quot2_num % 2 == 0)
			str = ft_start_pars2(mish, head, str, i);
		quot_check(str, i, &quot2_num, &quot_num);
		i++;
	}
	if (g_es == 0 && ++part)
	{
		quot_err(str, i, quot_num, quot2_num);
		str = ft_start_pars2(mish, head, str, i);
		free(str);
	}
	return (part);
}
