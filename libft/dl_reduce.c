/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_reduce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:11:25 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/23 23:12:49 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*dl_nxt_reduce(t_dlist *lst, void *initial, void *(*f)(void *, void *))
{
	while (lst)
	{
		initial = f(initial, lst->content);
		lst = lst->next;
	}
	return (initial);
}

void	*dl_prv_reduce(t_dlist *lst, void *initial, void *(*f)(void *, void *))
{
	while (lst)
	{
		initial = f(initial, lst->content);
		lst = lst->prev;
	}
	return (initial);
}
