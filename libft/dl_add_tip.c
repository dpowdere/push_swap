/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_add_tip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:13:03 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/18 16:13:10 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dl_add_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*cursor;

	if (!lst)
		return ;
	cursor = *lst;
	while (cursor && cursor->next)
		cursor = cursor->next;
	if (cursor)
	{
		cursor->next = new;
		new->prev = cursor;
	}
	else
		*lst = new;
}

void	dl_add_front(t_dlist **lst, t_dlist *new)
{
	t_dlist	*cursor;

	if (!lst || !new)
		return ;
	cursor = *lst;
	while (cursor && cursor->prev)
		cursor = cursor->prev;
	if (cursor)
	{
		cursor->prev = new;
		new->prev = cursor;
	}
	else
		*lst = new;
}
