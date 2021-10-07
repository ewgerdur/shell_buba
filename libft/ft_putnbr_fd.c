/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:50:39 by wgerdur           #+#    #+#             */
/*   Updated: 2020/11/06 16:23:16 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int j;

	j = 0;
	if (nb < 0)
	{
		j = nb * -1;
		ft_putchar_fd('-', fd);
	}
	if (nb >= 0)
		j = nb;
	if (j >= 10)
		ft_putnbr_fd(j / 10, fd);
	ft_putchar_fd((j % 10) + '0', fd);
}
