/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:58:05 by wgerdur           #+#    #+#             */
/*   Updated: 2020/11/04 18:59:44 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int result;
	int j;
	int q;

	result = 0;
	j = 0;
	q = 1;
	while (str[j] == ' ' || str[j] == '\0' || str[j] == '\n'
			|| str[j] == '\t' ||
			str[j] == '\v' || str[j] == '\f' || str[j] == '\r')
		j++;
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			q = -1;
		j++;
	}
	while (str[j] >= '0' && str[j] <= '9')
	{
		result = (10 * result) + str[j] - '0';
		j++;
	}
	return (q * result);
}
