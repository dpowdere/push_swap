/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpowdere <dpowdere@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 08:36:02 by dpowdere          #+#    #+#             */
/*   Updated: 2022/01/18 13:36:47 by dpowdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	*dl_pop(t_dlist **lst)
{
	void	*content;
	t_dlist	*elem;

	elem = *lst;
	content = elem->content;
	*lst = elem->next;
	if (*lst)
		(*lst)->prev = NULL;
	free(elem);
	return (content);
}
