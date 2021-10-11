/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_exec_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:28:31 by wgerdur           #+#    #+#             */
/*   Updated: 2021/10/11 19:28:36 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parsing_args(t_mish_save *mish, t_buba *lst)
{
	t_buba		*first;
	t_lst_args	*arg_lst;

	first = lst;
	while (first)
	{
		arg_lst = first->args_lst;
		if (arg_lst)
		{
			while (arg_lst)
			{
				if (!arg_lst->pars_arg)
					arg_lst->arg = parser(mish, arg_lst->arg);
				arg_lst = arg_lst->next;
			}
		}
		first = first->next;
	}
}

void	*ft_malloc_x(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_putendl_fd("Critical error: cannot allocate memmory", 2);
		exit(errno);
	}
	else
		return (ptr);
}

int	ft_lstsize_args(t_lst_args *lst)
{
	int			len;
	t_lst_args	*list;

	len = 0;
	list = lst;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}

char	**ft_lst_get_array(t_lst_args *lst)
{
	int		size_array;
	char	**arr;

	size_array = ft_lstsize_args(lst) + 1;
	arr = ft_malloc_x(sizeof(*arr) * size_array);
	if (!arr)
		return (NULL);
	arr[--size_array] = NULL;
	size_array = 0;
	while (lst)
	{
		arr[size_array] = ft_strdup(lst->arg);
		lst = lst->next;
		size_array++;
	}
	return (arr);
}

void	go_comman(t_mish_save *mish, t_buba *lst)
{
	t_buba	*el;

	el = lst;
	signal_pipes();
	parsing_args(mish, el);
	//while (el && g_es == 0)
	while (el)
	{
		get_arr(el);
		if (el->next)
		{
			if (pipe(el->fd) < 0)
			{
				err(NULL, "minishell");
				break ;
			}
			el->out = el->fd[1];
			el->next->in = el->fd[0];
			ft_execut(mish, el);
		}
		else
			last_exec(mish, el);
		el = el->next;
	}
	signal_first();
}
