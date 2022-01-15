/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_add_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 08:39:24 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/15 08:55:02 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dl_add_front(t_dlist **lst, t_dlist *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}
