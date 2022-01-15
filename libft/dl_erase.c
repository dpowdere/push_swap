/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:00:49 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/15 09:49:13 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "libft.h"

/*
** Erases an element and moves *lst pointer to the next one
*/

void	dl_erase(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*curr;

	if (!lst || !*lst || !del)
		return ;
	curr = *lst;
	if (curr->prev)
		curr->prev->next = curr->next;
	if (curr->next)
		curr->next->prev = curr->prev;
	*lst = curr->next;
	curr->next = NULL;
	curr->prev = NULL;
	(*del)(curr->content);
	free(curr);
}
