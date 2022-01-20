/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 08:36:02 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/20 16:36:31 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*dl_pop(t_dlist **lst)
{
	void	*content;
	t_dlist	*elem;

	if (!lst || !*lst)
		return NULL;
	elem = *lst;
	content = elem->content;
	if (elem->next && elem->prev)
	{
		elem->next->prev = elem->prev;
		elem->prev->next = elem->next;
	}
	else if (elem->next)
	{
		*lst = elem->next;
		(*lst)->prev = NULL;
	}
	else if (elem->prev)
	{
		*lst = elem->prev;
		(*lst)->next = NULL;
	}
	else
		*lst = NULL;
	free(elem);
	return (content);
}
