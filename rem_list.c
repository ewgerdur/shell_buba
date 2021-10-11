/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:44:10 by wgerdur           #+#    #+#             */
/*   Updated: 2021/10/11 19:44:12 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	found_len(char *found)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (found[++i] != '=' && found[++i])
	{
		count++;
	}
	return (count);
}

t_list	*delete_lst(t_list **lst, char *found)
{
	t_list	*elem;
	t_list	*tmp;

	elem = NULL;
	tmp = *lst;
	if (tmp && !ft_strncmp(tmp->content, found, found_len(found)))
	{
		elem = tmp;
		*lst = elem->next;
		elem->next = NULL;
		return (elem);
	}
	while (tmp && tmp->next)
	{
		if (!ft_strncmp(tmp->next->content, found, found_len(found)))
		{
			elem = tmp->next;
			tmp->next = tmp->next->next;
			elem->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	return (elem);
}

void	clear_lst( t_buba **lst)
{
	t_buba		*next;
	t_lst_args	*next_arg;

	while (*lst)
	{
		next = (*lst)->next;
		if ((*lst)->args_lst)
		{
			while ((*lst)->args_lst)
			{
				next_arg = (*lst)->args_lst->next;
				free((*lst)->args_lst->arg);
				free((*lst)->args_lst);
				(*lst)->args_lst = next_arg;
			}
		}
		ft_arrfree((*lst)->args);
		ft_arrfree((*lst)->redir);
		free(*lst);
		*lst = next;
	}
}

void	fr_lst(t_list *lst)
{
	if (lst)
	{
		free(lst->content);
		free(lst);
	}
}
