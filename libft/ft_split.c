/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:21:42 by wgerdur           #+#    #+#             */
/*   Updated: 2021/09/15 13:21:47 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_free(char **strs, size_t l)
{
	size_t	i;

	i = 0;
	while (i < l)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static int		ft_count_lines(char const *s, char c)
{
	size_t	i;
	size_t	lines;

	i = 0;
	lines = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			lines++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (lines);
}

static int		ft_strlen_c(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static char		**ft_make_arr(char const *s, size_t l, char c, char **strs)
{
	size_t	y;
	size_t	x;
	size_t	len;

	y = 0;
	while (y < l)
	{
		while (*s == c)
			s++;
		len = ft_strlen_c(s, c);
		if (!(strs[y] = (char *)malloc(sizeof(char *) * (len + 1))))
			return (ft_free(strs, l));
		x = 0;
		while (x < len)
			strs[y][x++] = *s++;
		strs[y][x] = '\0';
		y++;
	}
	strs[y] = 0;
	return (strs);
}

char			**ft_split(char const *s, char c)
{
	size_t	lines;
	char	**strs;

	if (!s)
		return (NULL);
	lines = ft_count_lines(s, c);
	if (!(strs = (char **)malloc(sizeof(char *) * (lines + 1))))
		return (NULL);
	strs = ft_make_arr(s, lines, c, strs);
	return (strs);
}
