/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:34:33 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/29 19:35:57 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dl_nxt_reverse(t_dlist **lst)
{
	t_dlist	*prv;
	t_dlist	*prv2;
	t_dlist	*cur;
	t_dlist	*nxt;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	prv = NULL;
	prv2 = (*lst)->prev;
	cur = *lst;
	while (cur)
	{
		nxt = cur->next;
		cur->next = prv;
		cur->prev = nxt;
		prv = cur;
		cur = nxt;
	}
	if (prv && prv2)
	{
		prv->prev = prv2;
		prv2->next = prv;
	}
	else if (prv && !prv2)
		*lst = prv;
}

void	dl_prv_reverse(t_dlist **lst)
{
	t_dlist	*prv;
	t_dlist	*prv2;
	t_dlist	*cur;
	t_dlist	*nxt;

	if (!lst || !*lst || !(*lst)->prev)
		return ;
	prv = NULL;
	prv2 = (*lst)->next;
	cur = *lst;
	while (cur)
	{
		nxt = cur->prev;
		cur->prev = prv;
		cur->next = nxt;
		prv = cur;
		cur = nxt;
	}
	if (prv && prv2)
	{
		prv->next = prv2;
		prv2->prev = prv;
	}
	else if (prv && !prv2)
		*lst = prv;
}
