/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_add_tip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:13:03 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/18 17:25:22 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dl_add_back_head(t_dlist **lst, t_dlist *head)
{
	t_dlist	*back;

	if (!lst || !head)
		return ;
	back = *lst;
	while (back && back->next)
		back = back->next;
	if (back)
	{
		back->next = head;
		head->prev = back;
	}
	else
		*lst = head;
}

void	dl_add_back_tail(t_dlist **lst, t_dlist *tail)
{
	t_dlist	*back;
	t_dlist *head;

	if (!lst || !tail)
		return ;
	back = *lst;
	while (back && back->next)
		back = back->next;
	head = tail;
	while (head && head->prev)
		head = head->prev;
	if (back)
	{
		back->next = head;
		head->prev = back;
	}
	else
		*lst = head;
}

void	dl_add_front_head(t_dlist **lst, t_dlist *head)
{
	t_dlist	*front;
	t_dlist *tail;

	if (!lst || !head)
		return ;
	front = *lst;
	while (front && front->prev)
		front = front->prev;
	tail = head;
	while (tail && tail->next)
		tail = tail->next;
	if (front)
	{
		front->prev = tail;
		tail->next = front;
	}
	*lst = head;
}

void	dl_add_front_tail(t_dlist **lst, t_dlist *tail)
{
	t_dlist	*front;
	t_dlist *head;

	if (!lst || !tail)
		return ;
	front = *lst;
	while (front && front->prev)
		front = front->prev;
	head = tail;
	while (head && head->prev)
		head = head->prev;
	if (front)
	{
		front->prev = tail;
		tail->next = front;
	}
	*lst = head;
}
