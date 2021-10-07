/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:33:53 by wgerdur           #+#    #+#             */
/*   Updated: 2020/11/09 16:40:25 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char            *ft_strjoin(char const *s1, char const *s2)
{
    char        *a;
    size_t        i;
    size_t        j;

    a = (char*)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*s1));
    if (!a || !s1 || !s2)
        return (0);
    i = 0;
    j = 0;
    while (s1[i])
    {
        a[j] = s1[i];
        i++;
        j++;
    }
    i = 0;
    while (s2[i])
    {
        a[j] = s2[i];
        i++;
        j++;
    }
    a[j] = '\0';
    return (a);
}
