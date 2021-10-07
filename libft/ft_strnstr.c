/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:31:54 by wgerdur           #+#    #+#             */
/*   Updated: 2020/11/16 17:08:06 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	j = ft_strlen(needle);
	i = 0;
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (0);
	if (haystack == NULL && needle == NULL)
		return (0);
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && len >= ft_strlen(needle))
	{
		if (needle[0] == haystack[i])
			if (0 == ft_strncmp(&haystack[i], needle, j))
				return ((char *)&haystack[i]);
		len--;
		i++;
	}
	return (0);
}
