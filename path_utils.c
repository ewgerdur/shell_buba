#include "minishell.h"

static	char	*search_path(char *envp[])
{
	char	*str;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 5))
			str = envp[i];
		i++;
	}
	return (str);
}

static char	*multiple_path_check(char **paths, char **args)
{
	int		i;
	int		fd;
	char	*tmp;
	char	*start;

	i = 1;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		start = ft_strjoin(tmp, args[0]);
		free(tmp);
		fd = open(start, O_RDONLY);
		if (fd > 0)
		{
			close(fd);
			ft_arrfree(paths);
			return (start);
		}
		free(start);
		close(fd);
		i++;
	}
	ft_arrfree(paths);
	return (NULL);
}

char	*find_path(char *env_var_name, char **env)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], env_var_name, ft_strlen(env_var_name)))
		{
			if (env[i][ft_strlen(env_var_name)] == '=')
			{
				str = env[i];
				break ;
			}
		}
		i++;
	}
	if (str != NULL)
		str = ft_substr(str, ft_strlen(env_var_name) + 1, ft_strlen(str));
	return (str);
}

char	*path_operations(char **envp, char **args, char **path, char **tmp)
{
	char	**binary_paths;
	char	*first_path;
	char	*head;
	int		fd;

	*path = search_path(envp);
	binary_paths = ft_split(*path, ':');
	first_path = ft_substr(binary_paths[0], 5, ft_strlen(binary_paths[0]) - 5);
	*tmp = ft_strjoin(first_path, "/");
	free(first_path);
	head = ft_strjoin(*tmp, args[0]);
	free(*tmp);
	fd = open(head, O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		return (head);
	}
	close(fd);
	free(head);
	return (multiple_path_check(binary_paths, args));
}

char	*file_name_export(const char *redir, int type)
{
	int	counter;

	if (type == 1 || type == 2)
		counter = 1;
	else
		counter = 2;
	while (redir[counter] == ' ')
		counter++;
	return (ft_substr(redir, counter, ft_strlen(redir)));
}
