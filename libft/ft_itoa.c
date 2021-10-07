/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:07:47 by wgerdur           #+#    #+#             */
/*   Updated: 2020/11/09 17:11:49 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_le(int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

char			*ft_itoa(int nbr)
{
	char	*str;
	int		size;
	int		sign;

	sign = 1;
	size = ft_le(nbr);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1 + (nbr < 0)))))
		return (0);
	if (nbr == 0)
		str[0] = '0';
	str[size + (nbr < 0)] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		sign = -1;
	}
	size--;
	while (nbr != 0)
	{
		str[size + (nbr < 0)] = (nbr % 10) * sign + '0';
		nbr /= 10;
		size--;
	}
	return (str);
}
