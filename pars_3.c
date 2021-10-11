/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:09:04 by wgerdur           #+#    #+#             */
/*   Updated: 2021/10/11 20:09:06 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

t_lst_args	*ft_lstlast_args(t_lst_args *lst)
{
	t_lst_args	*list;

	if (!lst)
		return (NULL);
	list = lst;
	while (list->next)
		list = list->next;
	return (list);
}

void	get_arr(t_buba *el)
{
	ft_arrfree(el->args);
	el->args = ft_lst_get_array(el->args_lst);
}

int	k_search(char c)
{
	if (c == '_' || ft_isalnum(c))
		return (1);
	return (0);
}

void	begin_main(t_mish_save *mish, char **env, char **argv, int argc)
{
	char	*lvl;
	char	*tmp;
	char	*new;

	void_aae(env, argv, argc);
	g_es = 0;
	mish->stat_buba = 0;
	set_env(mish, env);
	mish->env_mish = ft_lst_get_arrayf(mish->env_lst);
	lvl = find_path("SHLVL", mish->env_mish);
	tmp = ft_itoa(ft_atoi(lvl) + 1);
	new = ft_strjoin("SHLVL=", tmp);
	new_envp(mish, new);
	free(lvl);
	free(tmp);
	free(new);
	save_dups(mish);
	close_dups(mish);
	signal_first();
}
