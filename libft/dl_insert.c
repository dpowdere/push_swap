/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:49:55 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/15 09:59:16 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

void	dl_insert(t_dlist **current, t_dlist *new_next)
{
	t_dlist	*lst;

	if (current == NULL || new_next == NULL)
		return ;
	if (*current == NULL)
		*current = new_next;
	else
	{
		lst = dl_last(new_next);
		lst->next = (*current)->next;
		(*current)->next->prev = lst;
		(*current)->next = new_next;
	}
	new_next->prev = *current;
}
