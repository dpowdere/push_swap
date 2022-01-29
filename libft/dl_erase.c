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
** Erases an element and returns the next one if available,
** or the previous one.
*/

t_dlist	*dl_erase(t_dlist *curr, void (*del)(void *))
{
	t_dlist	*ret;

	if (!curr || !del)
		return (curr);
	if (curr->prev)
		curr->prev->next = curr->next;
	if (curr->next)
		curr->next->prev = curr->prev;
	ret = curr->next;
	if (!ret)
		ret = curr->prev;
	(*del)(curr->content);
	free(curr);
	return (ret);
}
