/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_extend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:17:46 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/20 17:17:57 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dl_extend_tail_head(t_dlist **tail1, t_dlist *head2)
{
	t_dlist	*tail2;

	if (!tail1 || !head2)
		return ;
	tail2 = head2;
	while (tail2 && tail2->next)
		tail2 = tail2->next;
	if (*tail1)
	{
		(*tail1)->next = head2;
		head2->prev = *tail1;
	}
	*tail1 = tail2;
}

void	dl_extend_tail_tail(t_dlist **tail1, t_dlist *tail2)
{
	t_dlist	*head2;

	if (!tail1 || !tail2)
		return ;
	head2 = tail2;
	while (head2 && head2->prev)
		head2 = head2->prev;
	if (*tail1)
	{
		(*tail1)->next = head2;
		head2->prev = *tail1;
	}
	*tail1 = tail2;
}

void	dl_extend_head_head(t_dlist **head1, t_dlist *head2)
{
	t_dlist	*tail2;

	if (!head1 || !head2)
		return ;
	tail2 = head2;
	while (tail2 && tail2->next)
		tail2 = tail2->next;
	if (*head1)
	{
		(*head1)->prev = tail2;
		tail2->next = *head1;
	}
	*head1 = head2;
}

void	dl_extend_head_tail(t_dlist **head1, t_dlist *tail2)
{
	t_dlist	*head2;

	if (!head1 || !tail2)
		return ;
	head2 = tail2;
	while (head2 && head2->prev)
		head2 = head2->prev;
	if (*head1)
	{
		(*head1)->prev = tail2;
		tail2->next = *head1;
	}
	*head1 = head2;
}
