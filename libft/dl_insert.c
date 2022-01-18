/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:49:55 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/18 20:40:52 by dpowdere         ###   ########.fr       */
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

/*
static void debug(t_dlist *curr, t_dlist *prev, t_dlist *head, t_dlist *tail)
{
	ft_eprint("curr=" AEC_GREEN);
	if (curr)
		ft_eprint((char *)curr->content);
	ft_eprint(AEC_RESET ", prev=" AEC_GREEN);
	if (prev)
		ft_eprint((char *)prev->content);
	ft_eprint(AEC_RESET ", head=" AEC_GREEN);
	if (head)
		ft_eprint((char *)head->content);
	ft_eprint(AEC_RESET ", tail=" AEC_GREEN);
	if (tail)
		ft_eprint((char *)tail->content);
	ft_eprint(AEC_RESET "\n");
}
*/

void	dl_prv_insert_head(t_dlist **curr, t_dlist *head)
{
	t_dlist	*tail;
	t_dlist *prev;

	if (curr == NULL || head == NULL)
		return ;
	if (*curr == NULL)
		*curr = head;
	else
	{
		tail = dl_last(head);
		prev = (*curr)->prev;
		head->prev = prev;
		tail->next = *curr;
		(*curr)->prev = tail;
		if (prev)
			prev->next = head;
	}
}

void	dl_prv_insert_tail(t_dlist **curr, t_dlist *tail)
{
	t_dlist	*head;
	t_dlist	*prev;

	if (curr == NULL || tail == NULL)
		return ;
	if (*curr == NULL)
		*curr = dl_first(tail);
	else
	{
		head = dl_first(tail);
		prev = (*curr)->prev;
		head->prev = prev;
		tail->next = *curr;
		(*curr)->prev = tail;
		if (prev)
			prev->next = head;
	}
}
