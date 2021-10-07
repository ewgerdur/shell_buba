/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:27:41 by wgerdur           #+#    #+#             */
/*   Updated: 2020/11/11 14:16:55 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,
size_t len)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s)
	{
		if (!(newstr = (char*)malloc(sizeof(*s) * (len + 1))))
			return (0);
		while (s[i])
		{
			if (i >= start && j < len)
			{
				newstr[j] = s[i];
				j++;
			}
			i++;
		}
		newstr[j] = '\0';
		return (newstr);
	}
	return (NULL);
}
