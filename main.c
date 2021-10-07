#include "minishell.h"
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	t_buba	*buba;
	char		*str;
	unsigned int part;
	t_mish_save		mish;

	(void)argc;
	(void)argv;
	//buba = NULL;
	begin_main(&mish, env);
	while (1)
	{
		buba = NULL;
		//str = readline("minishell> ");
		if (exit_stat == 130)
		{
			mish.stat_buba = 1;
			exit_stat = 0;
		}
		str = readline("minishell> ");
		free_lst_mish(&mish, str);
		//if (ft_strlen(str) == 0)
		//	continue ;
		if (str && ft_strlen(str) > 0)
		{
			add_history(str);
			part = ft_start_pars1(&mish, str, &buba);
			go_comman(&mish, buba);
			mish.stat_buba = exit_stat;
			clear_mem(buba);
			exit_stat = 0;
		}
	}
}
