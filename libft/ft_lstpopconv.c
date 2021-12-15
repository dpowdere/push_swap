/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopconv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:30:39 by dpowdere          #+#    #+#             */
/*   Updated: 2021/12/08 17:33:38 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

/*
** Unlike `ft_lstpop` it does not free an element, but reuses it,
** changing its content and detaching it from the list.
*/
t_list	*ft_lstpopconv(t_list **lst, void *(*f)(void *))
{
	t_list	*converted_item;

	converted_item = *lst;
	if (converted_item)
	{
		if (f)
			converted_item->content = f((*lst)->content);
		*lst = (*lst)->next;
		converted_item->next = NULL;
	}
	return (converted_item);
}

t_list	*ft_lstpopconv_xd(t_list **lst,
						void *(*f)(void *, void *),
						void *extra_data)
{
	t_list	*converted_item;

	converted_item = *lst;
	if (converted_item)
	{
		converted_item->content = f((*lst)->content, extra_data);
		*lst = (*lst)->next;
		converted_item->next = NULL;
	}
	return (converted_item);
}
