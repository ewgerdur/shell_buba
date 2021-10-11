/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:46:16 by wgerdur           #+#    #+#             */
/*   Updated: 2021/10/11 19:46:18 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_buba	*ft_lstlast_mish(t_buba *lst)
{
	t_buba	*list;

	if (!lst)
		return (NULL);
	list = lst;
	while (list->next)
		list = list->next;
	return (list);
}

void	free_list(t_list **lst)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		fr_lst(*lst);
		*lst = next;
	}
}

void	ft_lstadd_back_mish(t_buba **lst, t_buba *new)
{
	t_buba	*list;

	if (lst && new)
	{
		list = *lst;
		if (list == NULL)
		{
			*lst = new;
			new->next = NULL;
		}
		else
		{
			list = ft_lstlast_mish(*lst);
			list->next = new;
			new->next = NULL;
		}
	}
}

t_buba	*ft_lstnew_mish(char **args, char **redirs,
						t_lst_args *args_lst)
{
	t_buba	*list;

	list = (t_buba *) malloc(sizeof(t_buba));
	if (!list)
		return (NULL);
	list->args = args;
	list->redir = redirs;
	list->out = 1;
	list->in = 0;
	list->next = NULL;
	list->args_lst = args_lst;
	list->fd[1] = -1;
	list->fd[0] = -1;
	return (list);
}

char	**make_arr_from_lst(t_list *lst)
{
	char	**arr;
	int		len;

	len = ft_lstsize(lst) + 1;
	arr = (char **) malloc(sizeof(char *) * len);
	if (arr == NULL)
		return (NULL);
	arr[--len] = NULL;
	while (lst)
	{
		arr[--len] = ft_strdup(lst->content);
		lst = lst->next;
	}
	return (arr);
}
