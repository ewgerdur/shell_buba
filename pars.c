#include "minishell.h"

void	ft_lstadd_back_args(t_lst_args **lst, t_lst_args *new)
{
	t_lst_args	*list;

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
			list = ft_lstlast_args(*lst);
			list->next = new;
			new->next = NULL;
		}
	}
}

t_lst_args	*ft_lstnew_args(char *arg, int is_parsed)
{
	t_lst_args	*list;

	list = (t_lst_args *) malloc(sizeof(t_lst_args));
	if (!list)
		return (NULL);
	list->arg = arg;
	list->pars_arg = is_parsed;
	return (list);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
	{
		new_ptr = malloc(size);
		if (new_ptr == NULL)
		{
			ft_putstr_fd("Malloc exception\n", 2);
			exit(errno);
		}
	}
	if (!size)
		return (ptr);
	new_ptr = malloc(size);
	if (new_ptr == NULL)
	{
		ft_putstr_fd("Malloc exception\n", 2);
		exit(errno);
	}
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

int 	ft_if_2(t_mish_save *mish, char *arg, int count_redir)
{
	if (check_spaces(arg))
		return (redir_exec(mish, arg, count_redir));
	else
	{
		free(arg);
		return (0);
	}
}

int	redir_parser(t_mish_save *mish, int *i, char *tmp, int count_redir)
{
	int		big_redir;
	int		less_redir;
	int		j;
	char	*arg;

	big_redir = 0;
	less_redir = 0;
	j = *i;
	if (tmp[*i] == '>')
		big_redir = 1;
	else if (tmp[*i] == '<')
		less_redir = 1;
	(*i)++;
	if ((tmp[*i] == '>' && big_redir) || (tmp[*i] == '<' && less_redir))
		(*i)++;
	while (tmp[*i] && tmp[*i] == ' ' && tmp[*i] != '\"')
		(*i)++;
	while (tmp[*i] && tmp[*i] != ' ' && tmp[*i] != '\"')
		(*i)++;
	arg = ft_substr(tmp, j, *i - j);
	count_redir = ft_if_2(mish, arg, count_redir);
	(*i) -= 1;
	return (count_redir);
}
