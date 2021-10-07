/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:41:36 by wgerdur           #+#    #+#             */
/*   Updated: 2020/11/06 16:20:50 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	d_count;
	size_t	s_count;

	d_count = ft_strlen(dst);
	s_count = ft_strlen(src);
	i = 0;
	j = d_count;
	if (d_count < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && d_count + i < dstsize - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (d_count >= dstsize)
		d_count = dstsize;
	return (d_count + s_count);
}
