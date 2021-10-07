/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:26:02 by wgerdur           #+#    #+#             */
/*   Updated: 2020/11/04 16:28:10 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int size;

	size = ft_strlen(s);
	while (size >= 0)
	{
		if (s[size] == c)
			return (((char *)s + size));
		size--;
	}
	return (0);
}
