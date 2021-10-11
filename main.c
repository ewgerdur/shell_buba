/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:22:08 by wgerdur           #+#    #+#             */
/*   Updated: 2021/10/11 20:22:24 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_buba			*buba;
	char			*str;
	unsigned int	part;
	t_mish_save		mish;

	begin_main(&mish, env, argv, argc);
	while (1)
	{
		buba = NULL;
		str = readline("minishell> ");
		free_lst_mish(&mish, str);
		if (str && ft_strlen(str) > 0)
		{
			add_history(str);
			part = ft_start_pars1(&mish, str, &buba, part);
			go_comman(&mish, buba);
			mish.stat_buba = g_es;
			clear_mem(buba);
			g_es = 0;
		}
	}
}
