/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:19:00 by mbenicho          #+#    #+#             */
/*   Updated: 2022/05/10 19:19:01 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*cpy;

	new = 0;
	if (!f || !lst || !del)
		return (0);
	while (lst)
	{
		cpy = ft_lstnew(f(lst->content));
		if (!cpy)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, cpy);
		lst = lst->next;
	}
	return (new);
}
