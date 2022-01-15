/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 08:55:49 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/15 08:57:07 by dpowdere         ###   ########.fr       */
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
