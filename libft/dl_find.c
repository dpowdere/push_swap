/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 08:33:33 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/28 08:43:43 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		dl_nxt_find(t_dlist *lst, void *data)
{
	int	ix;

	ix = 0;
	while (lst)
	{
		if (lst->content == data)
			return (ix);
		lst = lst->next;
		++ix;
	}
	return (-1);
}

int		dl_prv_find(t_dlist *lst, void *data)
{
	int	ix;

	ix = 0;
	while (lst)
	{
		if (lst->content == data)
			return (ix);
		lst = lst->prev;
		++ix;
	}
	return (-1);
}
