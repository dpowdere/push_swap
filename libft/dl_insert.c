/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:49:55 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/18 16:06:03 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

void	dl_nxt_insert_head(t_dlist **curr, t_dlist *head)
{
	t_dlist	*tail;

	if (curr == NULL || head == NULL)
		return ;
	if (*curr == NULL)
		*curr = head;
	else
	{
		tail = dl_last(head);
		head->prev = *curr;
		tail->next = (*curr)->next;
		if ((*curr)->next)
			(*curr)->next->prev = tail;
		(*curr)->next = head;
	}
}

void	dl_nxt_insert_tail(t_dlist **curr, t_dlist *tail)
{
	t_dlist	*head;

	if (curr == NULL || tail == NULL)
		return ;
	if (*curr == NULL)
		*curr = dl_first(tail);
	else
	{
		head = dl_first(tail);
		head->prev = *curr;
		tail->next = (*curr)->next;
		if ((*curr)->next)
			(*curr)->next->prev = tail;
		(*curr)->next = head;
	}
}

void	dl_prv_insert_head(t_dlist **curr, t_dlist *head)
{
	t_dlist	*tail;

	if (curr == NULL || head == NULL)
		return ;
	if (*curr == NULL)
		*curr = head;
	else
	{
		tail = dl_last(head);
		tail->next = *curr;
		head->prev = (*curr)->prev;
		if ((*curr)->prev)
			(*curr)->prev->next = head;
		(*curr)->prev = tail;
	}
}

void	dl_prv_insert_tail(t_dlist **curr, t_dlist *tail)
{
	t_dlist	*head;

	if (curr == NULL || tail == NULL)
		return ;
	if (*curr == NULL)
		*curr = dl_first(tail);
	else
	{
		head = dl_last(tail);
		tail->next = *curr;
		head->prev = (*curr)->prev;
		if ((*curr)->prev)
			(*curr)->prev->next = head;
		(*curr)->prev = tail;
	}
}
