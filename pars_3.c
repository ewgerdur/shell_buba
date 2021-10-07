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

void	begin_main(t_mish_save *mish, char **env)
{
	(void)env;
	exit_stat = 0;
	mish->stat_buba = 0;
	set_env(mish, env);
	mish->env_mish = ft_lst_get_arrayf(mish->env_lst);
	make_lvl(mish);
	save_dups(mish);
	close_dups(mish);
	signal_first();
}
