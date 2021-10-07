#include <fcntl.h>
#include "libft/libft.h"
#include "memory.h"
#include "minishell.h"

/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *) malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}*/

char	*ft_slesh(char *str, int *i)
{
	char	*new;
	char	*after;
	char	*tmp;

	new = ft_substr(str, 0, *i);
	after = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(new, after);
	free(new);
	free(after);
	free(str);
	++(*i);
	return (tmp);
}

char	*free_sle_one(char *str, int j, int *i)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*final;

	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	tmp3 = ft_strdup(str + *i + 1);
	final = tmp;
	tmp = ft_strjoin(tmp, tmp2);
	free(final);
	tmp = ft_strjoin(tmp, tmp3);
	free(tmp2);
	free(tmp3);
	return (tmp);
}

char	*ft_sle(char *str, int *i)
{
	int		j;
	char	*tmp;

	j = *i;
	while (str[++(*i)])
		if (str[(*i)] == '\'')
			break ;
	tmp = free_sle_one(str, j, i);
	free(str);
	(*i) -= 1;
	return (tmp);
}

void	question_mark(t_mish_save *mish)
{
	char	*tmp;

	tmp = ft_itoa(mish->stat_buba);
	exit_stat = 127;
	ft_putstr_fd(tmp, 2);
	ft_putstr_fd(": command not found\n", 2);
	free(tmp);
}
