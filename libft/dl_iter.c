/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_iter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 21:48:56 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/18 15:52:45 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "libft.h"

void	dl_nxt_iter(t_dlist *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

void	dl_prv_iter(t_dlist *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->prev;
	}
}

/*
** Have the extra pieces of data on every cycle of interation:
** 1-based index of the element of a list and whether it is the last one
** in the list or not.
*/
void	dl_nxt_iter_ix(t_dlist *lst, void (*f)(void *data, int ix, int is_last))
{
	int	ix;

	ix = 0;
	while (lst)
	{
		f(lst->content, ++ix, lst->next == NULL);
		lst = lst->next;
	}
}

void	dl_prv_iter_ix(t_dlist *lst, void (*f)(void *data, int ix, int is_1st))
{
	int	ix;

	ix = 0;
	while (lst)
	{
		f(lst->content, ++ix, lst->prev == NULL);
		lst = lst->prev;
	}
}
