#include "minishell.h"

char	*ft_start_pars2(t_mish_save *mish, t_buba **head, char *str, int i)
{
	char	*tmp;
	int		count_args;
	int		count_redir;

	tmp = init_variables_pars(mish, str, &i, &count_args);
	count_redir = 0;
	mish->args_lst = NULL;
	while (tmp[i] && exit_stat == 0)
	{
		if (tmp[i] == '\"' && (!char_in_string(tmp[i], " <>\n\t\0") || tmp[i]
				== '\\'))
			count_args += quot2_pars(mish, &i, tmp, count_args);
		else if (tmp[i] && (tmp[i] == '>' || tmp[i] == '<'))
			count_redir = redir_parser(mish, &i, tmp, count_redir);
		else if (tmp[i] == '\'' && (!char_in_string(tmp[i], " <>\n\t\0")
				|| tmp[i] == '\\'))
			count_args += quot_pars(mish, &i, tmp, count_args);
		else if (!char_in_string(tmp[i], " <>\n\t\0") || tmp[i] == '\\')
			count_args += pure_pars(mish, &i, tmp, count_args);
		i++;
	}
	if (count_args == 0 && count_redir == 0 && exit_stat == 0)
		pipes_correctness_error();
	struct_lists_creating(mish, head, count_redir, count_args);
	return (free_strings(tmp, str));
}

int	ft_start_pars1(t_mish_save *mish, char *str, t_buba **head)
{
	unsigned int	quot_num;
	unsigned int	quot2_num;
	int	i;
	unsigned int	part;

	quot_num = 0;
	quot2_num = 0;
	part = 0;
	i = 0;
	if (str[i] == ';' || str[i] == '|')
	{
		ft_putstr_fd("Incorrect begin of the line\n", 2);
		exit_stat = 258;
	}
	while (str[i] && exit_stat == 0)
	{
		synt_err(str, i);
		if (str[i] == '|' && quot_num % 2 == 0 && quot2_num % 2 == 0)
		{
			str = ft_start_pars2(mish, head, str, i);
			i = 0;
			part++;
		}
		quot_check(str, i, &quot2_num, &quot_num);
		i++;
	}
	if (exit_stat == 0)
	{
		quot_err(str, i, quot_num, quot2_num);
		str = ft_start_pars2(mish, head, str, i);
		free(str);
	}
	part++;
	return (part);
}
