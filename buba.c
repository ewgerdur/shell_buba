/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:39:43 by wgerdur           #+#    #+#             */
/*   Updated: 2021/10/11 19:39:45 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status;

void	clear_mem(t_buba *lst)
{
	if (lst)
		clear_lst(&lst);
}

void	save_dups(t_mish_save *mish)
{
	mish->mish_in = dup(0);
	mish->mish_out = dup(1);
	if (mish->mish_in < 0 || mish->mish_out < 0)
		err(0, 0);
}

void	close_dups(t_mish_save *mish)
{
	close(0);
	close(1);
	if (dup2(mish->mish_in, 0) < 0)
		err(0, 0);
	if (dup2(mish->mish_out, 1) < 0)
		err(0, 0);
	close(mish->mish_in);
	close(mish->mish_out);
}
