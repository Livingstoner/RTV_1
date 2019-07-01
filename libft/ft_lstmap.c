/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhokhlo <rkhokhlo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 15:36:23 by rkhokhlo          #+#    #+#             */
/*   Updated: 2018/10/31 15:36:24 by rkhokhlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *beg_list;

	list = f(lst);
	beg_list = list;
	if (lst == NULL)
		return (NULL);
	if (list == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
		list->next = f(lst);
		if (list->next == NULL)
			return (NULL);
		list = list->next;
	}
	return (beg_list);
}
