/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 08:33:40 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/18 15:59:34 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	dl_nxt_size(t_dlist *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		++size;
	}
	return (size);
}

int	dl_prv_size(t_dlist *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->prev;
		++size;
	}
	return (size);
}
