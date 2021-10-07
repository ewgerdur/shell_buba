/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgerdur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:03:45 by wgerdur           #+#    #+#             */
/*   Updated: 2020/11/16 16:35:19 by wgerdur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lnew;
	t_list	*enew;

	if (!lst || !f)
		return (0);
	lnew = NULL;
	while (lst)
	{
		if (!(enew = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lnew, del);
			return (0);
		}
		ft_lstadd_back(&lnew, enew);
		lst = lst->next;
	}
	return (lnew);
}
