/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_tip.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:12:47 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/18 16:12:52 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*dl_first(t_dlist *lst)
{
	while (lst && lst->prev)
		lst = lst->prev;
	return (lst);
}

t_dlist	*dl_last(t_dlist *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
