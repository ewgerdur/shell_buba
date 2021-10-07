#include "minishell.h"

void	ft_arrfree(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	redir_exec(t_mish_save *mish, char *redir, int count_redir)
{
	mish->redirs = (char **) ft_realloc(mish->redirs, sizeof(char *)
			* (count_redir + 1));
	mish->redirs[count_redir] = ft_strdup(redir);
	free(redir);
	count_redir++;
	return (count_redir);
}

int	pure_pars(t_mish_save *mish, int *i, char *tmp, int count_args)
{
	int		j;
	char	*arg;

	if (tmp[*i] == '\\')
		j = (*i) + 1;
	else
		j = *i;
	while (tmp[*i] && (tmp[*i] != ' ' || (*i != 0 && tmp[(*i) - 1] == '\\')))
		(*i)++;
	arg = ft_substr(tmp, j, *i - j);
	if (check_spaces(arg))
	{
		mish->args = (char **)ft_realloc(mish->args, sizeof(char *) * (count_args
					+ 1));
		mish->args[count_args] = ft_strdup(arg);
		ft_lstadd_back_args(&mish->args_lst, ft_lstnew_args(ft_strdup(arg), 0));
		free(arg);
		return (1);
	}
	free(arg);
	return (0);
}

void	struct_lists_creating(t_mish_save *mish, t_buba **head, int count_redir,
							  int count_args)
{
	mish->redirs = (char **)ft_realloc(mish->redirs,
			sizeof(char *) * (count_redir + 1));
	mish->args = (char **)ft_realloc(mish->args, sizeof(char *) * (count_args
				+ 1));
	/*mish->redirs = (char **)ft_realloc(mish->redirs,
			sizeof(char *) * (count_redir + 1));*/
	mish->redirs[count_redir] = NULL;
	mish->args[count_args] = NULL;
	ft_lstadd_back_mish(head, ft_lstnew_mish(mish->args, mish->redirs, mish->args_lst));
}

char	**ft_lst_get_arrayf(t_list *lst)
{
	int		size_array;
	char	**arr;

	size_array = ft_lstsize(lst) + 1;
	arr = ft_malloc_x(sizeof(*arr) * size_array);
	if (!arr)
		return (NULL);
	//arr[--size_array] = NULL;
	arr[size_array-1] = NULL;
	size_array = 0;
	while (lst)
	{
		arr[size_array] = ft_strdup(lst->content);
		lst = lst->next;
		size_array++;
	}
	return (arr);
}
