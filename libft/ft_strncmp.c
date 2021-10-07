/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:39:32 by wgerdur           #+#    #+#             */
/*   Updated: 2020/11/06 16:22:22 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (j < n && ((a[i] && b[i]) != '\0'))
	{
		if (a[i] == b[i] && (a[i] != '\0' && b[i] != '\0'))
		{
			i++;
			j++;
		}
		else if (a[i] != b[i])
			return (a[i] - b[i]);
	}
	if (a[i] == '\0' && b[i] != '\0' && j < n)
		return (-1);
	else if (a[i] != '\0' && b[i] == '\0' && j < n)
		return (1);
	return (0);
}
