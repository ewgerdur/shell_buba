/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:45:15 by wgerdur           #+#    #+#             */
/*   Updated: 2020/11/06 16:19:31 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	a;
	int		i;

	str = (char *)s;
	a = (char)c;
	i = 0;
	if (c == '\0')
		return (str + ft_strlen(s));
	while (str[i])
	{
		if (str[i] == a)
			return (&(str[i]));
		i++;
	}
	return (0);
}
