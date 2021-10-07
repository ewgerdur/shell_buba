/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:11:57 by wgerdur           #+#    #+#             */
/*   Updated: 2020/11/06 16:27:39 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned
int, char))
{
	char		*newstr;
	size_t		i;

	i = 0;
	if (s)
	{
		if (!(newstr = ft_strdup(s)))
			return (0);
		while (s[i])
		{
			newstr[i] = (*f)(i, s[i]);
			i++;
		}
		return (newstr);
	}
	return (0);
}
