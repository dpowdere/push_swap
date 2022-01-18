/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 08:58:00 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/18 15:54:09 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

void	dl_nxt_clear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*cursor;
	t_dlist	*empty_element;

	if (!lst || !del)
		return ;
	cursor = *lst;
	while (cursor)
	{
		(*del)(cursor->content);
		empty_element = cursor;
		cursor = cursor->next;
		empty_element->next = NULL;
		empty_element->prev = NULL;
		free(empty_element);
	}
	*lst = NULL;
}

void	dl_prv_clear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*cursor;
	t_dlist	*empty_element;

	if (!lst || !del)
		return ;
	cursor = *lst;
	while (cursor)
	{
		(*del)(cursor->content);
		empty_element = cursor;
		cursor = cursor->prev;
		empty_element->next = NULL;
		empty_element->prev = NULL;
		free(empty_element);
	}
	*lst = NULL;
}
