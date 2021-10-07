/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:13:32 by wgerdur           #+#    #+#             */
/*   Updated: 2020/11/06 16:06:42 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	i = -1;
	if (!dst && !src)
		return (dst);
	if (a <= b)
	{
		while (++i < len)
			a[i] = b[i];
	}
	else
	{
		i = len;
		while (i > 0)
		{
			a[i - 1] = b[i - 1];
			i--;
		}
	}
	return (dst);
}
