/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:52:46 by wgerdur           #+#    #+#             */
/*   Updated: 2020/11/09 17:08:49 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_buba(char c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		st;
	size_t		en;
	char		*str;

	if (!s1 || !set)
		return (0);
	st = 0;
	while (s1[st] && ft_buba(s1[st], set))
		st++;
	en = ft_strlen(s1);
	while (en > st && ft_buba(s1[en - 1], set))
		en--;
	if (!(str = (char*)malloc((en - st + 1) * sizeof(*s1))))
		return (0);
	i = 0;
	while (st < en)
		str[i++] = s1[st++];
	str[i] = 0;
	return (str);
}
