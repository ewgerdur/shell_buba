/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_updating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:30:09 by wgerdur           #+#    #+#             */
/*   Updated: 2021/10/11 19:30:15 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_env(t_mish_save *mish)
{
	int		len;
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	len = ft_arrlen(mish->env_mish);
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (compare_strings(mish->env_mish[j], mish->env_mish[j + 1]) > 0)
			{
				buffer = mish->env_mish[j];
				mish->env_mish[j] = mish->env_mish[j + 1];
				mish->env_mish[j + 1] = buffer;
			}
			j++;
		}
		i++;
	}
}

void	remove_elem(t_mish_save *mish, char *found)
{
	t_list	*lst;

	lst = delete_lst(&mish->env_lst, found);
	if (lst)
	{
		ft_arrfree(mish->env_mish);
		fr_lst(lst);
		mish->env_mish = make_arr_from_lst(mish->env_lst);
	}
}

void	new_envp(t_mish_save *mish, char *found)
{
	remove_elem(mish, found);
	ft_lstadd_front(&mish->env_lst, ft_lstnew(ft_strdup(found)));
	ft_arrfree(mish->env_mish);
	mish->env_mish = make_arr_from_lst(mish->env_lst);
}

void	set_env(t_mish_save *mish, char **env)
{
	int	i;

	mish->env_lst = NULL;
	i = 0;
	while (env[i])
	{
		ft_lstadd_back(&mish->env_lst, ft_lstnew(ft_strdup(env[i])));
		if (i == 0)
			mish->first = mish->env_lst;
		i++;
	}
}
